/* bsl_loaderdesc.h - Interface for VM Loader Descriptor
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#ifndef __CmVM_LoadDesc_h
#define __CmVM_LoadDesc_h

#include "loader.h"

// Private VM Loader Function Pointer Types:
typedef u8 (*VMLoad)(u8 *mem);
typedef u8 (*VMStatus)(void);

// Private Interface Loader Descriptor
typedef struct IVMLoaderDesc {
    VMLoad   ld;
    VMStatus st;
} IVMLoadDesc;

#endif
