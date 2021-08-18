#include "ir_receiver.h"

void setup(){
  Serial.begin(9600);
  init_ir_receiver();
}

void loop(){
  if (irrecv.decode(&ir_results)){
    translateIR();
    delay(500);
    irrecv.resume();
  }  
}
