/* in.h - Cm VM Console Input Interface.
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#ifndef __CmVM_VMIn_h
#define __CmVM_VMIn_h

#include "bsl_in.h"

void VMIn_Init(IIn in);

char VMIn_GetC(void);

#endif
