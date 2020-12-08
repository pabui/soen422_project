#include "bsl_indesc.h"
#include "in.h"

static IIn vmIn;

void VMIn_Init(IIn in)  { vmIn = in;  }

char VMIn_GetC(void)    { return vmIn->gc();  }
