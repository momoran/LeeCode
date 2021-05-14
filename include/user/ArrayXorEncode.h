#ifndef _ARRAYXORENCODE_H
#define _ARRAYXORENCODE_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>

class ArrayXorEncode : public StdLibBase
{
public:
    ArrayXorEncode() = default;
    virtual ~ArrayXorEncode() override = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    std::vector<int> decode(std::vector<int>& encoded);
    std::vector<int> m_encodeArray;
    std::vector<int> result;
    std::vector<int> hopeResult;
};

#endif