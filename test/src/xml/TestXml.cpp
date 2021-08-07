// Copyright 2021 jaimeyang  All rights reserved.
//
// All components of Drake are licensed under the BSD 3-Clause License.
#include "TestXml.h"
#include "xml/XmlParse.h"
namespace CDBC {
TEST_F(TestXml, test_parse) {
    auto p = cdbc_make_unique<XmlParse>();
    XmlNode* root = nullptr;
    cdbc_str path("../test/resources/test.xml");
    p.get()->parse(path, root);
}
}
