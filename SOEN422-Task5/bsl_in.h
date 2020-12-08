/* bsl_in.h - Interface for Cm VM Input Interface
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#ifndef __CmVM_In_h
#define __CmVM_In_h

#include "bsl_stdtype.h"

        struct IVMInDesc;
typedef struct IVMInDesc* IIn;

IIn In_GetFactory(const char* whichOne);

#endif
