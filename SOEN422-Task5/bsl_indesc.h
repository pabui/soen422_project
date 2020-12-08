/* bsl_indesc.h - Interface for VM Input Descriptor
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#ifndef __CmVM_InDesc_h
#define __CmVM_InDesc_h

#include "in.h"

// Private VM Input Function Pointer Types:
typedef char (*VMGetC)(void);

// Private Interface Input Descriptor
typedef struct IVMInDesc {
    VMGetC gc;
} IVMInDesc;

#endif
