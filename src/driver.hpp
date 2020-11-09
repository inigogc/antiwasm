#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <thread>
#include <mutex>
#include <string>

#ifndef DRIVER_H
#define DRIVER_H

class Driver {
    private:
        static Driver *instance_;
        static std::mutex mutex_;

    protected:
        Driver()
        {
        }

        ~Driver() {}

        static size_t fileSize_;
        static size_t pointer_;
        static char *buffer_;  //TODO which size?
        std::ifstream wasmFile_;


    public:
        Driver(Driver &driver) = delete;
        Driver *GetInstance(const char* fileName);
        unsigned char* GetNextBytes(size_t nBytes);
        unsigned char* GetUTF8String();
        void CloseFile();
};

Driver* Driver::instance_{nullptr};
std::mutex Driver::mutex_;
size_t Driver::fileSize_ = 0;
size_t Driver::pointer_ = 0;
char *Driver::buffer_ = nullptr;

Driver *Driver::GetInstance(const char* fileName)
{
    std::cout << "GetInstance: " << fileName << std::endl;
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr)
    {
        instance_ = new Driver();
        instance_->pointer_ = 0;
        instance_->wasmFile_.open(fileName, std::ifstream::in);
        instance_->wasmFile_.seekg(0, std::ios::end);
        //instance_->fileSize_ = wasmFile_.tellg(); FIXME

	    std::cout << "Size of file: " << instance_->fileSize_ << std::endl;
        instance_->wasmFile_.seekg(0, std::ios::beg);
    }
    std::cout << "Returning instance" << std::endl;
    return instance_;
}

unsigned char* Driver::GetNextBytes(size_t nBytes)
{
    std::cout << "GetNextBytes: " << nBytes << std::endl;
    char* buffer = (char*)malloc(sizeof(char) * nBytes + 1);
    instance_->wasmFile_.seekg(instance_->pointer_, std::ios::beg);
    instance_->pointer_ += nBytes;
    instance_->wasmFile_.read(buffer, nBytes);

    for(int i = 0; i < nBytes; i++) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");

    return (unsigned char*)buffer;
}

unsigned char* Driver::GetUTF8String() //TODO not ready to be used
{
    std::cout << "GetUTF8String: " << std::endl;
    unsigned char delimiter = 0x03;
    std::string temp = "";
    
    instance_->wasmFile_.seekg(instance_->pointer_, std::ios::beg);
    std::istream& stream = instance_->wasmFile_;
    getline(stream, temp);

    return nullptr;
}

void Driver::CloseFile()
{
    instance_->wasmFile_.close();
}

#endif
