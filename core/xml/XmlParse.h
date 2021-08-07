// Copyright 2021 jaimeyang  All rights reserved.
//
// All components of Drake are licensed under the BSD 3-Clause License.
#ifndef CORE_XML_XMLPARSE_H_
#define CORE_XML_XMLPARSE_H_
#include "StdInclude.h"
#include <memory>
namespace CDBC {
class XmlNode {
    XmlNode() = default;
    ~XmlNode() = default;
    //  元素的名字
    cdbc_str m_element;
    //  值
    cdbc_str m_value;
    //  属性
    cdbc_u_map<cdbc_str, cdbc_str> m_attr;
    //  孩子节点
    cdbc_vec<cdbc_uni_ptr<XmlNode>> m_children;
};
class XmlParse {
 public:
    XmlParse() = default;
    ~XmlParse() = default;
    void parse(const cdbc_str& path, XmlNode* root);
};
}   // namespace CDBC
#endif   // CORE_XML_XMLPARSE_H_
