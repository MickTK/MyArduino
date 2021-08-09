#include <NintendoExtensionCtrl.h>

ClassicController classic;

int LX_default, LY_default, RX_default, RY_default;
const int tolerable = 20;
bool values[23];

void setup() {
	Serial.begin(9600);
	classic.begin();

	for(int i = 0; i < 23; i++)
		values[i] = false;

	LX_default = 131;
	LY_default = 125;
	RX_default = 128;
	RY_default = 130;

	while (!classic.connect()) {
		Serial.println("Classic Controller not detected!");
		delay(1000);
	}
}

void loop() {
	if (!classic.update()) {
		Serial.println("Controller disconnected!");
		delay(1000);
	}
	else {
		/* DPAD */
		if(values[0] != classic.dpadLeft()){
			values[0] = classic.dpadLeft();
			Serial.println("A");
		}
		if(values[1] != classic.dpadRight()){
			values[1] = classic.dpadRight();
			Serial.println("B");
		}
		if(values[2] != classic.dpadUp()){
			values[2] = classic.dpadUp();
			Serial.println("C");
		}
		if(values[3] != classic.dpadDown()){
			values[3] = classic.dpadDown();
			Serial.println("D");
		}
			
		/* Buttons */
		if(values[4] != classic.buttonA()){
			values[4] = classic.buttonA();
			Serial.println("E");
		}
		if(values[5] != classic.buttonB()){
			values[5] = classic.buttonB();
			Serial.println("F");
		}
		if(values[6] != classic.buttonX()){
			values[6] = classic.buttonX();
			Serial.println("G");
		}
		if(values[7] != classic.buttonY()){
			values[7] = classic.buttonY();
			Serial.println("H");
		}

		//
		if(values[8] != classic.buttonL()){
			values[8] = classic.buttonL();
			Serial.println("I");
		}
		if(values[9] != classic.buttonZL()){
			values[9] = classic.buttonZL();
			Serial.println("J");
		}
		if(values[10] != classic.buttonR()){
			values[10] = classic.buttonR();
			Serial.println("K");
		}
		if(values[11] != classic.buttonZR()){
			values[11] = classic.buttonZR();
			Serial.println("L");
		}

		//
		if(values[12] != classic.buttonMinus()){
			values[12] = classic.buttonMinus();
			Serial.println("M");
		}
		if(values[13] != classic.buttonHome()){
			values[13] = classic.buttonHome();
			Serial.println("N");
		}
		if(values[14] != classic.buttonPlus()){
			values[14] = classic.buttonPlus();
			Serial.println("O");
		}
			
		// Left joystick
		if(values[15] != (classic.leftJoyX() <= LX_default - tolerable)){
			values[15] = !values[15];
			Serial.println("P");
		}
		if(values[16] != (classic.leftJoyX() >= LX_default + tolerable)){
			values[16] = !values[16];
			Serial.println("Q");
		}
		if(values[17] != (classic.leftJoyY() >= LY_default + tolerable)){
			values[17] = !values[17];
			Serial.println("R");
		}
		if(values[18] != (classic.leftJoyY() <= LY_default - tolerable)){
			values[18] = !values[18];
			Serial.println("S");
		}

		// Right joystick
		if(values[19] != (classic.rightJoyX() <= RX_default - tolerable)){
			values[19] = !values[19];
			Serial.println("T");
		}
		if(values[20] != (classic.rightJoyX() >= RX_default + tolerable)){
			values[20] = !values[20];
			Serial.println("U");
		}
		if(values[21] != (classic.rightJoyY() >= RY_default + tolerable)){
			values[21] = !values[21];
			Serial.println("V");
		}
		if(values[22] != (classic.rightJoyY() <= RY_default - tolerable)){
			values[22] = !values[22];
			Serial.println("W");
		}

		//classic.printDebug();
	}
}
