#include "bsl_loaderdesc.h"

static u8 status;
static u32 startAddress;
static u32 downloadSize;

// Listener
static u8 ListenAndParse(u8 *mem) {

    u8 i = 0;
    u8 checksumLoc = 0;
    u8 size, checksumRecv, cmd, byte;

    size = VMIn_GetC();
    checksumRecv = VMIn_GetC();

    u8 data[size - 2];

    // Receive data
    while (i < (size - 2)) {
        byte = VMIn_GetC();
        data[i] = byte;
        checksumLoc = checksumLoc + byte;
        i++;
    }

    u8 zero = VMIn_GetC();
    if (zero != 0) status = InvalidCmd;

    if (checksumRecv != (checksumLoc & 0xFF)) status = InvalidCmd;

    cmd = data[0];
    switch (cmd) {
        case Ping:
        case Run: break;
        case GetStatus: return cmd;
        case Download:
            // clear prev values
            startAddress = 0;
            downloadSize = 0;
            startAddress |= (data[1] << 0x18) | (data[2] << 0x10) | (data[3] << 0x8) | data[4];
            downloadSize |= (data[5] << 0x18) | (data[6] << 0x10) | (data[7] << 0x8) | data[8];
            break;
        case SendData:

            if ((size - 3) > 8) {
                status = InvalidCmd;
                break;
            }
            if ((startAddress + (size - 3)) > MemMax) {
                status = InvalidAddr;
                break;
            }
            if ((downloadSize - (size - 3)) < 0) {
                status = InvalidCmd;
                break;
            }
            // Load data into memory
            for (i = 1; i < (size - 2); i++) {
                mem[startAddress] = data[i];
                startAddress++;
                downloadSize--;
            }
            break;
        case Reset:
            // Clear downloa
            startAddress = 0;
            downloadSize = 0;
            for (i = 0; i < MemMax; i++) {
                mem[i] = 0;
            }
            break;
        default: status = UnknownCmd;
    }

    return cmd;
}

static void SerialLoader_Init() {
    status = Success;
    startAddress = 0;
    downloadSize = 0;
}

static u8 Load(u8 *mem) { return ListenAndParse(mem); }

static u8 FetchStatus() { return status; }

static IVMLoadDesc serialloader = {
    Load,
    FetchStatus
};

static bool init = 0;

ILoader Loader_GetFactory(const char* separate) {
    if (!init) {
        separate = 0;
        SerialLoader_Init();
        init = true;
    }
    return &serialloader;
}
