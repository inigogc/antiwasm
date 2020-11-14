#ifndef TYPES_PARSER_HPP
#define TYPES_PARSER_HPP

#include <iostream>

namespace antiwasm {
    void parseFuncTypeVec(unsigned char* funcTypeVecSection);
    void parseFuncType(unsigned char* funcTypeSection, int &pointer);
    void parseResultType(unsigned char* resultTypeSection, int &pointer);
    void parseValType(unsigned char valType);
    void parseGlobalVec(unsigned char *globalSectionBuffer);
    void parseInstr(unsigned char *instruction, int &pointer);
    void parseElementVec(unsigned char *elementVec);
    void parseFuncIdxVec(unsigned char* funcIdxVec, int &pointer);
    void parseDataVec(unsigned char *dataVec);
    void parseByteVec(unsigned char * byteVec, int pointer);
}

#endif
