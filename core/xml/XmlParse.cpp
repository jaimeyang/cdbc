// Copyright 2021 jaimeyang  All rights reserved.
//
// All components of Drake are licensed under the BSD 3-Clause License.
#include "XmlParse.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/xml_parser.hpp"
#include "spdlog/spdlog.h"
#include "boost/foreach.hpp"
namespace CDBC {
namespace pt = boost::property_tree;
void XmlParse::parse(const cdbc_str& path, XmlNode* root) {
    spdlog::set_level(spdlog::level::debug);
    pt::ptree pt1;
    boost::property_tree::xml_parser::read_xml(path, pt1);
    auto test = pt1.get<cdbc_str>("mapping.class");
    // pt1.get_child_optional<cdbc_str>("");
    BOOST_FOREACH(pt::ptree::value_type &v,
                  pt1.get_child("mapping.class.<xmlattr>")) {
        spdlog::debug(v.second.data());
    }
}
}
