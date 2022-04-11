#include <Arduino.h>

int PWM = 4;  //pulse/
int INA1 = 5; // 方向
int INA2 = 6; // 方向
char cmd[10];
int recv;

// L/H 正轉
// H/L 反轉
// L/L 停止

void setup() {
  Serial.begin(9600);

  //初始設定
  pinMode(INA1, OUTPUT);
  pinMode(INA2, OUTPUT);
//  digitalWrite(PWM, HIGH);

  //設定正反轉
  digitalWrite(INA1, LOW);
  digitalWrite(INA2, LOW);
}

void loop() {

  if (recv == 0) {
    digitalWrite(INA1, LOW);
    digitalWrite(INA2, LOW);
  }
  else if (recv == 1) {
    digitalWrite(INA1, LOW);
    digitalWrite(INA2, HIGH);
  }
  else {
    digitalWrite(INA1, HIGH);
    digitalWrite(INA2, LOW);
  }

  if (Serial.available() > 0) {
    // read the incoming byte:
    Serial.readBytes(cmd, 10);
    recv = atoi(cmd);
    //這邊沒有值的時候會一直收到0，所以上方recv == 0，要都設定成LOW
    Serial.println(atoi(recv));
//    steptimes();
  }
}

//void  steptimes( ) {
//  for (int counter = 0; counter <= 200; counter++) {
//    delayMicroseconds(2000);
//  }
//}
