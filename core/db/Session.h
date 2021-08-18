// Copyright 2021 jaimeyang  All rights reserved.
//
// All components of Drake are licensed under the BSD 3-Clause License.
#ifndef CORE_DB_SESSION_H_
#define CORE_DB_SESSION_H_
#include "StdInclude.h"
namespace CDBC {
class Session {
 public:
    Session() = default;
    ~Session() = default;
    virtual int connect(const cdbc_str& addr,
    int port, const cdbc_str& type) = 0 {};
    virtual int excuate(const cdbc_str& statement) = 0 {};
};
}
#endif