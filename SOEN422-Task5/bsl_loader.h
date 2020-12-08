/* bsl_loader.h - Interface for Cm VM Loader Interface
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#ifndef __CmVM_Loader_h
#define __CmVM_Loader_h

#include "bsl_stdtype.h"

// Maximum size of memory allowed on system
#define MemMax 36

// Statuses to be sent to host
#define Success     0x40
#define UnknownCmd  0x41
#define InvalidCmd  0x42
#define InvalidAddr 0x43
#define MemoryFail  0x44

// Acknowledged or Not Acknowledged
// To be sent to host
#define Ack         0xCC
#define Nak         0x33

// Host Commands to VM
#define Ping        0x20
#define Download    0x21
#define GetStatus   0x23
#define SendData    0x24
#define Run         0x22
#define Reset       0x25

        struct IVMLoaderDesc;
typedef struct IVMLoaderDesc* ILoader;

ILoader Loader_GetFactory(const char* whichOne);

#endif
