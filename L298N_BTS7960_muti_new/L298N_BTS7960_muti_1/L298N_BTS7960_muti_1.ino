#include <Arduino.h>

int PWM1 = 5; //pulse/
int INA3 = 6; // 方向
int INA4 = 7; // 方向

int PWM3 = 10; //pulse/
int INA7 = 9;  // 方向
int INA8 = 8;  // 方向

int pin13 = 13;


char cmd[10];
int recv;

// L/H 正轉
// H/L 反轉
// L/L 停止

void setup() {
  Serial.begin(9600);

  //初始設定
  pinMode(INA3, OUTPUT);
  pinMode(INA4, OUTPUT);

  pinMode(INA7, OUTPUT);
  pinMode(INA8, OUTPUT);

  pinMode(PWM1, OUTPUT);
  pinMode(PWM3, OUTPUT);

  analogWrite(PWM1, 0);
  analogWrite(PWM3, 0);

  pinMode(pin13, OUTPUT);

  //設定正反轉
  digitalWrite(INA3, LOW);
  digitalWrite(INA4, LOW);

  digitalWrite(INA7, LOW);
  digitalWrite(INA8, LOW);

}

void loop() {

  //靜止
  if (recv == 0) {

    digitalWrite(INA3, LOW);
    digitalWrite(INA4, LOW);

    digitalWrite(INA7, LOW);
    digitalWrite(INA8, LOW);

    analogWrite(PWM1, 0);
    analogWrite(PWM3, 0);
  }

  //往前
  else if (recv == 1) {

    analogWrite(PWM1, 80);
    analogWrite(PWM3, 80);

    digitalWrite(INA3, LOW);
    digitalWrite(INA4, HIGH);

    digitalWrite(INA7, HIGH);
    digitalWrite(INA8, LOW);
  }
  //往後
  else if (recv == 2) {
    analogWrite(PWM1, 80);
    analogWrite(PWM3, 80);

    digitalWrite(INA3, HIGH);
    digitalWrite(INA4, LOW);

    digitalWrite(INA7, LOW);
    digitalWrite(INA8, HIGH);
  }

  //向前往左
  else if (recv == 3) {
    analogWrite(PWM1, 127);
    analogWrite(PWM3, 64);

    digitalWrite(INA3, LOW);
    digitalWrite(INA4, HIGH);

    digitalWrite(INA7, HIGH);
    digitalWrite(INA8, LOW);
  }

  //向前往右
  else if (recv == 4) {

    analogWrite(PWM1, 64);
    analogWrite(PWM3, 127);

    digitalWrite(INA3, LOW);
    digitalWrite(INA4, HIGH);

    digitalWrite(INA7, HIGH);
    digitalWrite(INA8, LOW);
  }

  else if (recv == 5) {
    digitalWrite(pin13, LOW);
  }

  else if (recv == 6) {
    digitalWrite(pin13, HIGH);
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
