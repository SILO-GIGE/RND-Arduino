#include <Stepper.h>

const int stepsPerRevolution = 200; // 모터 스텝각이 1.8도 이므로 360/1.8=200입력
Stepper myStepper(stepsPerRevolution, 12, 11); // 모터의 Dir 핀과 Clk 핀 번호 입력

int DirPIN = 12; // 1번자리
int ClkPIN = 11; // 2번자리
int Sm1PIN = 10; // 5번자리
int Sm2PIN = 9;  // 6번자리
int EnvPIN = 8;  // 8번자리

int a = 0;        //  gen counter (회전수를 기록하는 카운터)
int revDw = 1;
int revUp = 2800;

void setup()
{
  pinMode(DirPIN, OUTPUT);
  pinMode(ClkPIN, OUTPUT);
  pinMode(Sm1PIN, OUTPUT);
  pinMode(Sm2PIN, OUTPUT);
  pinMode(EnvPIN, OUTPUT);

  /*
     Sm1  Sm2
     H      H  :Half Step
     H      L  :Quarter Step
     L      H  :Eighth Step
     L      L  :Sixteeth Step
  */
  digitalWrite(DirPIN, HIGH);
  digitalWrite(ClkPIN, LOW);
  digitalWrite(Sm1PIN, HIGH); // Set Micro stepping to 1/8
  digitalWrite(Sm2PIN, HIGH); // 스탭모드를 L H(1/8)로 설정
  digitalWrite(EnvPIN, HIGH); // 모터 구동부 Enable

  myStepper.setSpeed(480); // set the motor speed (for multiple steps only):
  Serial.begin(9600);
  delay(3000);
}

void loop()
{
  if (Serial.available())
  {
    int targetPosition = Serial.parseInt(); // 시리얼 입력 값을 읽어옴

    // 입력 값이 유효한 범위 내에 있는지 확인
    if (targetPosition >= 0 && targetPosition <= stepsPerRevolution * 8)
    {
      int currentPosition = 0;
      int stepsToMove = targetPosition - currentPosition;

      // 입력한 위치로 스텝모터를 이동
      myStepper.step(stepsToMove);
    }
    else
    {
      Serial.println("Invalid position input. Enter a value between 0 and 1600.");
    }
  }
}
