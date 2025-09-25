#include <arduino.h>

void modPot2() {
    for (int i=0; i < 2; i++){
        digitalWrite(ledsABC[i], HIGH);
    }
}

void modPot3() {
    for (int i = 0; i < 3; i++){
        digitalWrite(ledsABC[i], HIGH);
    }
}

void modPot4() {
    for (int i =0; i < 4; i++) {
        digitalWrite(ledsABC[i], HIGH);
    }
}

void modPot5() {
    for (int i =0; i < 5; i++){
        digitalWrite(ledsABC[i], HIGH);
    }
}