#ifndef _CRC_H
#define _CRC_H
#include "operateLib.h"
#include <string.h>
namespace {
    constexpr WORD CRC_TABLE_LEN = 256;
}

class CRC
{
public:
    CRC() = default;
    virtual ~CRC() = default;
    WORD GenerateCRCTableReverse();
    WORD GenerateCRCTableNormal();
    DWORD CalculateCRC32Reverse(const BYTE* buf, WORD len);
    DWORD CalculateCRC32Normal(const BYTE* buf, WORD len);
    void SetOutFlag(bool xorOut, bool revOut, bool initFlag = true);
    void PrintOutFlag();
    void PrintCRC32Table();
private:
    DWORD reverseDword(DWORD num);
    DWORD HanleOutCRC(DWORD num);
    DWORD crc32Table[CRC_TABLE_LEN];
    DWORD m_defaultInit{0xFFFFFFFF};
    bool m_isDefaultInit{true};
    bool m_xorOut{false};
    bool m_revOut{false};
};


#endif
