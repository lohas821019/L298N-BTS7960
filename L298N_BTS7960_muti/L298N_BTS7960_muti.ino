#include <Arduino.h>

int PWM = 4;  //pulse/
int INA1 = 5; // 方向
int INA2 = 6; // 方向

int PWM1 = 8;  //pulse/
int INA3 = 9; // 方向
int INA4 = 10; // 方向

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

  pinMode(INA3, OUTPUT);
  pinMode(INA4, OUTPUT);
  //  digitalWrite(PWM, HIGH);

  //設定正反轉
  digitalWrite(INA1, LOW);
  digitalWrite(INA2, LOW);

  pinMode(INA3, OUTPUT);
  pinMode(INA4, OUTPUT);
}

void loop() {

  if (recv == 0) {
    digitalWrite(INA1, LOW);
    digitalWrite(INA2, LOW);

    digitalWrite(INA3, LOW);
    digitalWrite(INA4, LOW);
  }
  else if (recv == 1) {
    digitalWrite(INA1, LOW);
    digitalWrite(INA2, HIGH);

    digitalWrite(INA3, LOW);
    digitalWrite(INA4, HIGH);
  }
  else if (recv == 2) {
    digitalWrite(INA1, HIGH);
    digitalWrite(INA2, LOW);
    
    digitalWrite(INA3, HIGH);
    digitalWrite(INA4, LOW);
  }

  if (Serial.available() > 0) {
    // read the incoming byte:

    Serial.readBytes(cmd, 10);
    //Serial.readBytes()返回放置在緩衝區中的字符數。0 表示未找到有效數據。

    recv = atoi(cmd);
    //這邊沒有值的時候會一直收到0，所以上方recv == 0，要都設定成LOW，要不然會一直跑

    Serial.println(atoi(recv));
    //atoi將字符串轉換爲整型值。

  }
}
