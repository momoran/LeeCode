#ifndef _XMLLOAD_H
#define _XMLLOAD_H
#include "std_lib.h"
#include "operateLib.h"
#include "tinyxml2.h"
#include <string>
#include <map>

namespace {
    using NODE_TYPE = std::map<const char *, tinyxml2::XMLElement*>;

    std::map<tinyxml2::XMLError, std::string> errString = {
        {tinyxml2::XML_SUCCESS, "XML_SUCCESS"},
        {tinyxml2::XML_NO_ATTRIBUTE, "XML_NO_ATTRIBUTE"},
        {tinyxml2::XML_ERROR_FILE_NOT_FOUND, "XML_ERROR_FILE_NOT_FOUND"}
    };

    NODE_TYPE secondNode = {
        {"university", nullptr},
        {"place", nullptr},
        {"food", nullptr}
    };

    std::map<const char*, NODE_TYPE> rootNode = {
        {"city", secondNode}
    };
}

class xmlLoad : public StdLibBase
{
public:
    xmlLoad() = default;
    virtual ~xmlLoad() override = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    WORD LoadXmlFile(const std::string fileName);
    tinyxml2::XMLElement* GetRootElement();
    WORD XmlFunTest();

private:
    std::string filePath{"D:/Documents/programming/codeSet/LeeCode/LeeCode/data/"};
    tinyxml2::XMLDocument m_file;
    tinyxml2::XMLElement* m_rootElement{nullptr};
    int result;
    int hopeResult;
};

#endif