#include <SoftwareSerial.h>

// RXD -> 3
// TXD -> 2
// GND -> GND
// VCC -> 5v

#define BAUD_RATE 9600

extern SoftwareSerial bluetooth;

void init_bluetooth();

/*
    while(bluetooth.available()) { ...code... }
    bluetooth.println()
    bluetooth.write()
    bluetooth.read()
*/