//스위치가 열려있으면 0을 출력, 닫혀있으면 1을 출력
//풀다운 스위치
//풀업과 코드는 같지만 회로가 다르다
int pushButton =4;

void setup(){
    Serial.begin(9600);
    pinMode(pushButton,INPUT);
}

void loop(){
    int buttonState = digitalRead(pushButton);
    Serial.println(buttonState);
    delay(1);
}