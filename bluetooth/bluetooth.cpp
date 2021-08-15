#include "bluetooth.h"

SoftwareSerial bluetooth(2, 3);

void init_bluetooth(){
    bluetooth.begin(BAUD_RATE);
}