#include "../includes/driver.hpp"

inline std::shared_ptr<Driver> Driver::instance_;
inline std::mutex Driver::mutex_;
inline size_t Driver::fileSize_;
inline size_t Driver::pointer_;
inline char *Driver::buffer_;

std::shared_ptr<Driver> Driver::GetInstance(const char* fileName)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr)
    {
        instance_ = std::make_shared<Driver>();
        instance_->pointer_ = 0;
        instance_->wasmFile_.open(fileName, std::ifstream::in);
        instance_->wasmFile_.seekg(0, std::ios::end);
        instance_->fileSize_ = instance_->wasmFile_.tellg();
        instance_->isParsing_ = true;

        BOOST_LOG_TRIVIAL(debug) << "Size of file: " << instance_->fileSize_;
        instance_->wasmFile_.seekg(0, std::ios::beg);
    }
    return instance_;
}

std::shared_ptr<Driver> Driver::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr) //TODO exception
    {
        //return nullptr;
    }
    BOOST_LOG_TRIVIAL(debug) << "Returning instance";
    return instance_;
}

uint8_t* Driver::GetNextBytes(size_t nBytesToBeRead)
{
    if( hasReachedFileSize(nBytesToBeRead) )
        return nullptr; //TODO avoid using nullptr

    BOOST_LOG_TRIVIAL(debug) << "Getting next " << nBytesToBeRead << " bytes";
    char* buffer = (char*)malloc(sizeof(char) * nBytesToBeRead + 1);
    instance_->wasmFile_.seekg(instance_->pointer_, std::ios::beg);
    instance_->pointer_ += nBytesToBeRead;
    instance_->wasmFile_.read(buffer, nBytesToBeRead);

    for(int i = 0; i < nBytesToBeRead; i++) {
        printf(" %02x", buffer[i]); //TODO format with Boost
    }
    printf("\n");

    return (uint8_t*)buffer;
}

unsigned char* Driver::GetNextSectionHeader()
{
    return Driver::GetNextBytes(SIZE_OF_SECTION_HEADER);
}

unsigned char* Driver::GetUTF8String() //TODO not ready to be used
{
    BOOST_LOG_TRIVIAL(debug) << "Getting UTF8 String";
    unsigned char delimiter = 0x03;
    std::string temp;

    instance_->wasmFile_.seekg(instance_->pointer_, std::ios::beg);
    std::istream& stream = instance_->wasmFile_;
    getline(stream, temp);

    return nullptr;
}

void Driver::CloseFile() {
    instance_->wasmFile_.close();
}

bool Driver::hasReachedFileSize(size_t nextBytesSize) {
    if (pointer_ <= fileSize_ + nextBytesSize)
        return false;
    return true;
}

bool Driver::IsCurrentlyParsing() const {
    return isParsing_;
}
