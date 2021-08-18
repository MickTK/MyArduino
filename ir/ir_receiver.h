#include "IRremote.h"
#include "IRremoteInt.h"

#define IR_RECEIVER_PIN 11

#define POWER 0xFFA25D
#define FUNC_STOP 0xFFE21D
#define VOL_PLUS 0xFF629D
#define FAST_BACK 0xFF22DD
#define PAUSE 0xFF02FD
#define FAST_FORWARD 0xFFC23D
#define DOWN 0xFFE01F
#define VOL_MINUS 0xFFA857
#define UP 0xFF906F
#define EQ 0xFF9867
#define ST_REPT 0xFFB04F
#define N0 0xFF6897
#define N1 0xFF30CF
#define N2 0xFF18E7
#define N3 0xFF7A85
#define N4 0xFF10EF
#define N5 0xFF38C7
#define N6 0xFF5AA5
#define N7 0xFF42BD
#define N8 0xFF4AB5
#define N9 0xFF52AD
#define UNRECOGNIZED 0xFFFFFFFF

extern IRrecv irrecv;
extern decode_results ir_results;

void init_ir_receiver();
void translateIR();