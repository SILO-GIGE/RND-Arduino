//SG90서보모터 0~180사이를 angle배열 에 따라 움직이기
#include <Servo.h>

Servo myServo; // Servo 객체 생성
int angle[8]={0,45,90,135,180, 135, 45, 0};

int button5=A0;

void setup() {
  pinMode(button5,INPUT);
  myServo.attach(9); // 5 번핀 사용
  Serial.begin(9600);
  Serial.println("Hello");
}

void loop() {
  if (digitalRead(button5)==1){
    for(int i=0;i<8;i++){
      Serial.println("Angle = "+ String(angle[i]));
      myServo.write(angle[i]);
      delay(2000);
    }
  }
}