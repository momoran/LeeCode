#include "XMLoad.h"
#include <iostream>

WORD xmlLoad::execute()
{
    UpdateTestCase();
    result = LoadXmlFile("dream.xml");
    XmlFunTest();
    return VerifyResult();
}

WORD xmlLoad::LoadXmlFile(const std::string fileName)
{
    std::string str = filePath + fileName;
    m_file.LoadFile(str.c_str());
    WORD errCode = SUCESS;
    if (m_file.ErrorID() == tinyxml2::XML_SUCCESS) {
        m_rootElement = m_file.RootElement();
    } else {
        std::cout << "open file fail" << std::endl;
        errCode = FAILURE;
    }
    return errCode;
}

WORD xmlLoad::XmlFunTest()
{
    auto root = GetRootElement();
    WORD errCode = FAILURE;
    if (root != nullptr) {
        std::cout << root->Attribute("moudle") << std::endl;
        std::cout << root->FirstChildElement("P2")->GetText() << std::endl;
        errCode = SUCESS;
    }
    return errCode;
}

tinyxml2::XMLElement* xmlLoad::GetRootElement()
{
    return m_rootElement;
}

void xmlLoad::UpdateTestCase()
{
    hopeResult = SUCESS;
}

WORD xmlLoad::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}