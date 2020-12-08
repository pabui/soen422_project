/* loader.h - Cm VM Serial Loader Interface.
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#ifndef __CmVM_VMLoader_h
#define __CmVM_VMLoader_h

#include "bsl_loader.h"

void VMLoader_Init(ILoader loader);

u8 VMLoader_Load(u8 * mem);
u8 VMLoader_FetchStatus();

#endif
