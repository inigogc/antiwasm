#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../src/module_parser.cpp"

BOOST_AUTO_TEST_SUITE(module_parser_test)

    BOOST_AUTO_TEST_CASE(parseNextSection_canParseACorrectSection)
    {
        antiwasm::SectionId sectionId = antiwasm::SectionId::Custom;
        int sizeOfSection = 1;
        auto *contentOfSection = static_cast<unsigned char *>(malloc(
                sizeof(unsigned char) * sizeOfSection)); //Does not matter

        auto result = antiwasm::parseNextSection(sectionId, sizeOfSection, contentOfSection);

        BOOST_CHECK_EQUAL(sectionId, result.getSectionId());
        BOOST_CHECK_EQUAL(sizeOfSection, result.getSize());
        BOOST_CHECK_EQUAL(contentOfSection, result.getContent());
    }

    BOOST_AUTO_TEST_CASE(parseNextSection_createsABadSectionIfEncountersAnUnknownSection)
    {
        unsigned char nonExistingSectionId = 100;
        int sizeOfSection = 1;
        auto *contentOfSection = static_cast<unsigned char *>(malloc(
                sizeof(unsigned char) * sizeOfSection)); //Does not matter

        auto result = antiwasm::parseNextSection(nonExistingSectionId, sizeOfSection, contentOfSection);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Error, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseCustomSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Custom, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Custom, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseTypeSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Type, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Type, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseImportSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Import, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Import, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseFunctionSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Function, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Function, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseTableSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Table, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Table, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseMemorySection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Memory, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Memory, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseGlobalSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Global, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Global, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseExportSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Export, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Export, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseStartSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Start, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Start, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseElementSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Element, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Element, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseCodeSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Code, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Code, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseDataSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Data, sizeOfSection, nullptr);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Data, result.getSectionId());
    }

BOOST_AUTO_TEST_SUITE_END()
