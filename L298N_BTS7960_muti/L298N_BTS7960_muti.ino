#include <Arduino.h>

int PWM0 = 3; //pulse/
int INA1 = 4; // 方向
int INA2 = 2; // 方向

int PWM1 = 5; //pulse/
int INA3 = 6; // 方向
int INA4 = 7; // 方向

int PWM2 = 11; //pulse/
int INA5 = 12; // 方向
int INA6 = 13; // 方向

int PWM3 = 10; //pulse/
int INA7 = 9;  // 方向
int INA8 = 8;  // 方向


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

  pinMode(INA5, OUTPUT);
  pinMode(INA6, OUTPUT);

  pinMode(INA7, OUTPUT);
  pinMode(INA8, OUTPUT);

  analogWrite(PWM0, 0);
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
  analogWrite(PWM3, 0);

  //設定正反轉
  digitalWrite(INA1, LOW);
  digitalWrite(INA2, LOW);

  digitalWrite(INA3, LOW);
  digitalWrite(INA4, LOW);

  digitalWrite(INA5, LOW);
  digitalWrite(INA6, LOW);

  digitalWrite(INA7, LOW);
  digitalWrite(INA8, LOW);

}

void loop() {

  //靜止
  if (recv == 0) {
    analogWrite(PWM0, 0);
    analogWrite(PWM1, 0);
    analogWrite(PWM2, 0);
    analogWrite(PWM3, 0);

    digitalWrite(INA1, LOW);
    digitalWrite(INA2, LOW);

    digitalWrite(INA3, LOW);
    digitalWrite(INA4, LOW);

    digitalWrite(INA5, LOW);
    digitalWrite(INA6, LOW);

    digitalWrite(INA7, LOW);
    digitalWrite(INA8, LOW);
  }

  //往前
  else if (recv == 1) {

    analogWrite(PWM0, 127);
    analogWrite(PWM1, 127);
    analogWrite(PWM2, 127);
    analogWrite(PWM3, 127);

    digitalWrite(INA1, LOW);
    digitalWrite(INA2, HIGH);

    digitalWrite(INA3, LOW);
    digitalWrite(INA4, HIGH);

    digitalWrite(INA5, HIGH);
    digitalWrite(INA6, LOW);

    digitalWrite(INA7, HIGH);
    digitalWrite(INA8, LOW);

  }
  //往後
  else if (recv == 2) {
    analogWrite(PWM0, 127);
    analogWrite(PWM1, 127);
    analogWrite(PWM2, 127);
    analogWrite(PWM3, 127);

    digitalWrite(INA1, HIGH);
    digitalWrite(INA2, LOW);

    digitalWrite(INA3, HIGH);
    digitalWrite(INA4, LOW);

    digitalWrite(INA5, LOW);
    digitalWrite(INA6, HIGH);

    digitalWrite(INA7, LOW);
    digitalWrite(INA8, HIGH);
  }

  //向前往左
  else if (recv == 3) {

    analogWrite(PWM0, 127);
    analogWrite(PWM1, 127);
    analogWrite(PWM2, 64);
    analogWrite(PWM3, 64);

    digitalWrite(INA1, LOW);
    digitalWrite(INA2, HIGH);

    digitalWrite(INA3, LOW);
    digitalWrite(INA4, HIGH);

    digitalWrite(INA5, HIGH);
    digitalWrite(INA6, LOW);

    digitalWrite(INA7, HIGH);
    digitalWrite(INA8, LOW);
  }

  //向前往右
  else if (recv == 4) {

    analogWrite(PWM0, 64);
    analogWrite(PWM1, 64);
    analogWrite(PWM2, 127);
    analogWrite(PWM3, 127);

    digitalWrite(INA1, LOW);
    digitalWrite(INA2, HIGH);

    digitalWrite(INA3, LOW);
    digitalWrite(INA4, HIGH);

    digitalWrite(INA5, HIGH);
    digitalWrite(INA6, LOW);

    digitalWrite(INA7, HIGH);
    digitalWrite(INA8, LOW);
  };

  if (Serial.available() > 0) {
    // read the incoming byte:

    Serial.readBytes(cmd, 10);
    //Serial.readBytes()返回放置在緩衝區中的字符數。0 表示未找到有效數據。

    recv = atoi(cmd);
    //這邊沒有值的時候會一直收到0，所以上方recv == 0，要都設定成LOW，要不然會一直跑

    Serial.println(recv);
    //atoi將字符串轉換爲整型值。

  }
}
