#include "ir_receiver.h"

IRrecv irrecv(IR_RECEIVER_PIN);
decode_results ir_results;

void init_ir_receiver(){
    irrecv.enableIRIn();
}

void translateIR(){
    switch(ir_results.value){
        case POWER: Serial.println("POWER"); break;
        case FUNC_STOP: Serial.println("FUNC/STOP"); break;
        case VOL_PLUS: Serial.println("VOL+"); break;
        case FAST_BACK: Serial.println("FAST BACK");    break;
        case PAUSE: Serial.println("PAUSE");    break;
        case FAST_FORWARD: Serial.println("FAST FORWARD");   break;
        case DOWN: Serial.println("DOWN");    break;
        case VOL_MINUS: Serial.println("VOL-");    break;
        case UP: Serial.println("UP");    break;
        case EQ: Serial.println("EQ");    break;
        case ST_REPT: Serial.println("ST/REPT");    break;
        case N0: Serial.println("0");    break;
        case N1: Serial.println("1");    break;
        case N2: Serial.println("2");    break;
        case N3: Serial.println("3");    break;
        case N4: Serial.println("4");    break;
        case N5: Serial.println("5");    break;
        case N6: Serial.println("6");    break;
        case N7: Serial.println("7");    break;
        case N8: Serial.println("8");    break;
        case N9: Serial.println("9");    break;
        case UNRECOGNIZED: Serial.println(" REPEAT");break;  
        default: Serial.println("?");
    }
}
