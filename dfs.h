// Copyright (c) 2015, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: yanshiguang02@baidu.com

#ifndef  __DFS_H_
#define  __DFS_H_

#include <stdint.h>
#include <string>

class Dfs {
public:
    Dfs() {}
    virtual ~Dfs() {}
    virtual int32_t CreateDirectory(const std::string& path) = 0;
    virtual int32_t OpenFile(const std::string& filename, int32_t flags) = 0;
private:
    Dfs(const Dfs&);
    void operator=(const Dfs&);
};

typedef Dfs* (*DfsCreator)(const char*);
typedef void (*DfsDestroyer)(Dfs*);

#endif  //__DFS_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
