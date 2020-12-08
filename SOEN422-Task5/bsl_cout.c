#include "bsl_outdesc.h"
#include "bsl_xtoa.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <util/delay.h>

static void TxChar(char c) {
    while (!(UCSR0A & (1 << UDRE0)));

    UDR0 = c;
}

static void Console_Putchar(char c) { TxChar(c); }

static char buffer_current[12];

static void COut_Init(void) {
    // Configure TX pin for output
    DDRD |= (1 << PD1);

    // configure baud rate, set to 9600
    UBRR0 = 103;

    // Enable transmitting via UART
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    // Set the number of data bit to 8
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

static void COut_PutS(const char* s) { while (*s) Console_Putchar(*s++); }
static void COut_PutB(bool b)        { COut_PutS(b ? "true" : "false"); }
static void COut_PutC(char c)        { Console_Putchar(c); }
static void COut_PutI(i32  i)        { System_itoa(i, buffer_current); COut_PutS(buffer_current); }
static void COut_PutU(u32 u)        { _utoa(u, buffer_current, 0, 10); COut_PutS(buffer_current); }
static void COut_PutX(u32  x)        { _utoa(x, buffer_current, 0, 16); COut_PutS(buffer_current); }

static void COut_PutN(void)          { Console_Putchar('\n'); }

static IVMOutDesc cout = {
    COut_PutB,
    COut_PutC,
    COut_PutI,
    COut_PutU,
    COut_PutS,
    COut_PutX,
    COut_PutN
};

static bool init = 0;

IOut Out_GetFactory(const char* separate) {
    if (!init) {
        separate = 0;
        COut_Init();
        init = true;
    }
    return &cout;
}

#ifdef DebugXtoa

#include <util/delay.h>

#define MS_DELAY 1000

static void TestCout(void) {
    COut_PutS("Test xtoa\n");
    COut_PutS("12345678900ABCDEF\n");

    System_itoa(1234, buffer_current);            COut_PutS(buffer_current);
    _utoa(56789, buffer_current, 0, 10);    COut_PutS(buffer_current);
    _utoa(0xABCDEF, buffer_current, 0, 16); COut_PutS(buffer_current);
    COut_PutN();
}

int main (void) {
    Out_GetFactory("");

    while(1) {
        TestCout();

        PORTB |= _BV(PORTB5);  // Turn the LED on.
        _delay_ms(MS_DELAY);
        PORTB &= ~_BV(PORTB5); // Turn the LED on.
        _delay_ms(MS_DELAY);
    }
}
#endif
