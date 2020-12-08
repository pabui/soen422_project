#include "hal.h"
#include "out.h"
#include "in.h"
#include "loader.h"

void Hal_Init(void) {
    VMOut_Init(Out_GetFactory(""));
    VMIn_Init(In_GetFactory(""));
    VMLoader_Init(Loader_GetFactory(""));
