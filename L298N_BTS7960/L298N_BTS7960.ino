#include <Arduino.h>

//int PWM = 5;  //pulse/
//int INA1 = 6; // 方向
//int INA2 = 7; // 方向

int PWM = 9;  //pulse/
int INA1 = 10; // 方向
int INA2 = 11; // 方向

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
  else if (recv == 2) {
    digitalWrite(INA1, HIGH);
    digitalWrite(INA2, LOW);
  }
  else if (recv == 3) {
    digitalWrite(INA1, HIGH);
    digitalWrite(INA2, HIGH);
  }
  else if (recv == 4) {
    digitalWrite(INA1, HIGH);
    digitalWrite(INA2, LOW);
    analogWrite(PWM, 64);
    //    digitalWrite(INA2, HIGH);
  };


  if (Serial.available() > 0) {
    // read the incoming byte:

    Serial.readBytes(cmd, 10);
    //Serial.readBytes()返回放置在緩衝區中的字符數。0 表示未找到有效數據。

    recv = atoi(cmd);
    //這邊沒有值的時候會一直收到0，所以上方recv == 0，要都設定成LOW，要不然會一直跑

    Serial.println(recv);
    //atoi將字符串轉換爲整型值。

    //    steptimes();
  }
}

//void  steptimes( ) {
//  for (int counter = 0; counter <= 200; counter++) {
//    delayMicroseconds(2000);
//  }
//}
