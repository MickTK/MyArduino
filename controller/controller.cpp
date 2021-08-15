#include "controller.h"

#define LX_default 131
#define LY_default 125
#define RX_default 128
#define RY_default 130

ClassicController controller;

void init_controller(){
    while (!controller.connect()) {
        controller.begin();
		Serial.println("Wii Classic Controller not detected!");
		delay(1000);
	}
}
/*
    while(controller.update()){ ...code... }

    controller.dpadLeft()
    controller.dpadRight()
    controller.dpadUp()
    controller.dpadDown()
    controller.buttonA()
    controller.buttonB()
    controller.buttonX()
    controller.buttonY()
    controller.buttonL()
    controller.buttonZL()
    controller.buttonR()
    controller.buttonZR()
    controller.buttonMinus()
    controller.buttonHome()
    controller.buttonPlus()
    controller.leftJoyX()
    controller.leftJoyX()
    controller.rightJoyX()
    controller.rightJoyY()
*/
