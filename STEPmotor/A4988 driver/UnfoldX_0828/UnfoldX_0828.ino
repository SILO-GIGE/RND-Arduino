/*
스텝모터 제어코드
1바퀴=200스텝
속도단위 steps/seconds = 0.3 rpm,    60rpm=200steps/seconds
*/

#include <AccelStepper.h>
 
#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1
const int steps[ ]={200};//스텝수 배열
const int speed[ ]={200};//속도배열
const int time[ ]={1000};//지연시간배열
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin); //핀설정
int i=0;

void setup() {
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  stepper.setMaxSpeed(1000);
  
}

void loop() {
  stepper.setCurrentPosition(0);
  if(i>7) i=0;
  while(stepper.currentPosition() != steps[i])
  {
    stepper.setSpeed(speed[i]);
    stepper.runSpeed();
  }
  
  delay(time[i]);
  i++;

}