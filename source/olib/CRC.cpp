#include "CRC.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

WORD CRC::GenerateCRCTableReverse()
{
    DWORD poly = 0xEDB88320; //生成多项式
    for(int i = 0; i < CRC_TABLE_LEN; i++) {
        DWORD CRCTmp = i;
        for (int j = 0; j < 8; j++) {
            if (CRCTmp & 1) {
                CRCTmp = (CRCTmp >> 1) ^ poly;
            } else {
                CRCTmp >>= 1;
            }  
        }
        crc32Table[i] = CRCTmp; 
    }
    SetOutFlag(true, false);
    return 0;
}

WORD CRC::GenerateCRCTableNormal()
{
    DWORD poly = 0x04c11db7; //生成多项式
    for(int i = 0; i < CRC_TABLE_LEN; i++) {
        DWORD CRCTmp = i << 24;
        for (int j = 0; j < 8; j++) {
            if (CRCTmp & 0x80000000) {
                CRCTmp = (CRCTmp << 1) ^ poly;
            } else {
                CRCTmp <<= 1;
            }   
        }
        crc32Table[i] = CRCTmp; 
    }
    SetOutFlag(false, false);
    return 0;
}

void CRC::PrintCRC32Table()
{
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 8; j++) {
            std::cout << std::hex << crc32Table[i*8+j] << " ";
        }
        std::cout << std::endl;
    }
}

// 输入数据和输出数据按位反转
DWORD CRC::CalculateCRC32Reverse(const BYTE* buf, WORD len)
{
    DWORD CRC32_data = m_defaultInit;
    for (WORD i = 0; i != len; ++i) {
        DWORD t = (CRC32_data ^ buf[i]) & 0xFF;
        CRC32_data = ((CRC32_data >> 8) & 0xFFFFFFFF) ^ crc32Table[t];
    }

    return HanleOutCRC(CRC32_data);
}

// 输入输出不按位反转
DWORD CRC::CalculateCRC32Normal(const BYTE* buf, WORD len)
{
    DWORD CRC32_data = m_defaultInit;
    for (WORD i = 0; i != len; ++i) {
        DWORD t = ((CRC32_data >> 24) ^ buf[i]) & 0xFF;
        CRC32_data = ((CRC32_data << 8) & 0xFFFFFFFF) ^ crc32Table[t];
    }
    return HanleOutCRC(CRC32_data);
}

DWORD CRC::reverseDword(DWORD num)
{
    DWORD tmp = 0x00000000;
    for(int i = 0; i < 32; i++) {
        if ((num >> i) & 0x00000001) {
            tmp |= (0x80000000 >> i);
        }
    }
    return tmp;
}

void CRC::SetOutFlag(bool xorOut, bool revOut, bool initFlag)
{
    m_xorOut = xorOut;
    m_revOut = revOut;
    m_isDefaultInit = initFlag;
    m_defaultInit = m_isDefaultInit ? 0xFFFFFFFF : 0x00000000;
}

void CRC::PrintOutFlag()
{
    std::cout << "m_xorOut is " << (m_xorOut ? "true" : "false") << std::endl;
    std::cout << "m_revOut is " << (m_revOut ? "true" : "false") << std::endl;
    std::cout << "m_isDefaultInit is " << (m_isDefaultInit ? "true" : "false") 
              << std::hex << m_defaultInit << std::endl;
}

DWORD CRC::HanleOutCRC(DWORD num)
{
    DWORD tmp = m_revOut ? reverseDword(num) : num;
    tmp = m_xorOut ? tmp ^ 0xFFFFFFFF: tmp;
    return tmp;
}