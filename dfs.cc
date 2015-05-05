// Copyright (c) 2015, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: yanshiguang02@baidu.com

#include <assert.h>
#include <dlfcn.h>

#include "dfs.h"

const char* so_path = "./bfs_impl.so";

int main() {
    void* handle = dlopen(so_path, RTLD_NOW);
    if (handle == NULL) {
        fprintf(stderr, "Open %s fail\n", so_path);
        return 1;
    }

    dlerror();
    
    DfsCreator creator = (DfsCreator)dlsym(handle, "NewDfs");
    const char* err = dlerror();
    if (err != NULL) {
        fprintf(stderr, "Load NewDfs fail: %s\n", err);
        return 1;
    }
    
    Dfs* dfs = (*creator)("conf");
    assert(dfs != NULL);
    
    dfs->OpenFile("/tmp/tmp", 1);
    dfs->CreateDirectory("/tmp/dir");

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
