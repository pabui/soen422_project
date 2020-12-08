/* loader.c - Serial Loader for the VM
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#include "bsl_loaderdesc.h"
#include "loader.h"

static ILoader vmLoader;

void VMLoader_Init(ILoader loader)  { vmLoader = loader;  }

u8 VMLoader_Load(u8 *mem)    { return vmLoader->ld(mem);  }
u8 VMLoader_FetchStatus()    { return vmLoader->st();  }
