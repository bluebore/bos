// Copyright (c) 2015, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: yanshiguang02@baidu.com

#include "dfs.h"
#include <stdlib.h>
#include <stdio.h>

class BfsImpl : public Dfs {
public:
    virtual int32_t CreateDirectory(const std::string& path) {
        printf("CreateDirectory %s\n", path.c_str());
        return 0;
    } 
    virtual int32_t OpenFile(const std::string& filename, int32_t flags) {
        printf("OpenFile %s : %d\n", filename.c_str(), flags);
        return 0;
    }
};

extern "C" {

Dfs* NewDfs(const char*) {
    return new BfsImpl();
}

void DeleteDfs(Dfs* dfs) {
    delete dfs;
}

} // extern 'C'

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
