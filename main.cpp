#include "CommonInterferce.h"
#include "tinyxml2.h"

int main()
{
    std::map<WORD, std::string> output = {
        {SUCESS, "the result is ok"},
        {FAILURE, "the result is faiure"},
        {INVALID, "please init result"},
    };
    std::unique_ptr<StdLibBase> ptr(new StringOvrride());
    auto it = output.find(ptr->execute());
    if (it != output.end()) {
        std::cout << it->second << std::endl;
    }
    /*tinyxml2::XMLDocument doc;
    doc.LoadFile("D:/Documents/programming/codeSet/LeeCode/LeeCode/initdata/dream.xml");
    if (doc.ErrorID() == 0) {
        std::cout << "open xml success!" << std::endl;
    } else {
        std::cout << "open xml fail! errcode:" << doc.ErrorID() << std::endl;
    }
    tinyxml2::XMLElement* rootNode = doc.RootElement();
    std::cout << rootNode->FirstChildElement()->GetText() << std::endl;*/
    return 0;
}