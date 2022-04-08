#include <Arduino.h>

int PWM = 4;  //pulse/
int INA1 = 5; // 方向
int INA2 = 6; // 方向

// L/H 正轉
// H/L 反轉
// L/L 停止

void setup() {
  Serial.begin(9600);

  pinMode(INA1, OUTPUT);
  pinMode(INA2, OUTPUT);

  digitalWrite(INA1, LOW);
  digitalWrite(INA2, HIGH);
  digitalWrite(PWM, LOW);

}

void loop() {
  
  steptimes();
  
}

void  steptimes( ) {
  for (int counter = 0; counter <= 200; counter++) {
    //digitalWrite(PWM, HIGH);
    delayMicroseconds(1000);
    //digitalWrite(PWM, LOW);
    delayMicroseconds(1000);
  }
}
