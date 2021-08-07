// Copyright 2021 jaimeyang  All rights reserved.
//
// All components of Drake are licensed under the BSD 3-Clause License.
#ifndef CORE_STDINCLUDE_H_
#define CORE_STDINCLUDE_H_
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <utility>
template <class T, class k>
using cdbc_u_map = std::unordered_map<T, k>;
using cdbc_str = std::string;
template <class T>
using cdbc_vec = std::vector<T>;
template <class T>
using cdbc_uni_ptr = std::unique_ptr<T>;
template<class K, class... Args>
cdbc_uni_ptr<K> cdbc_make_unique(Args&&... args) {
    return std::make_unique<K>(std::forward<Args>(args)...);
}
#endif   //   CORE_STDINCLUDE_H_
