#include "bsl_stdtype.h"
#include "hal.h"
#include "bsl_loader.h"
#include "bsl_out.h"
#include "bsl_in.h"
#include "vm.h"

#define Target      "(ATMega328P)"
#define VMName      "Cm Virtual Machine "
#define AppSuffix   ""
#define AppName     "cm"
#define Version     " v0.1.00.1101a "
#define Copyright   "Copyright (c) 2001-2020  Michel de Champlain"

// Banner = VMname AppSuffix Version Copyright
static void DisplayBanner() {
    VMOut_PutS(VMName); VMOut_PutS(AppSuffix); VMOut_PutS(Version); VMOut_PutS(Target); VMOut_PutN();
    VMOut_PutS(Copyright); VMOut_PutN();
}


static u8  mem[MemMax];

int main() {
    u8 cmd, current, i;

    // Initialize memory to 0 (halting)
    for (i=0; i < MemMax; i++)
        mem[i] = 0;

    Hal_Init();
    VM_Init(mem);

    while (1) {
        cmd = VMLoader_Load(mem);
        // Fetch the current
        current = VMLoader_Fetchcurrent();

        if (current == Success || cmd == Getcurrent)
            VMOut_PutC((char)Ack);
        else {
            VMOut_PutC((char)Nak);
            VMOut_PutC((char)0);
            continue;
        }

        switch (cmd) {
            case Ping:
            case Download:
            case SendData: break;
            case Run:
                VM_execute(mem);
                break;
            case Getcurrent:
                //current value
                VMOut_PutC((char)current);
                break;
            case Reset:
                VM_Init(mem);
                break;
        }
        VMOut_PutC((char)0);

    }
    return 0;
}
