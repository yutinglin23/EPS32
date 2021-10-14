#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 2048;  //此馬達轉一圈為2048步
const int RPM = 5; //馬達旋轉速度

const int BTN1 = 2;
const int BTN2 = 22;

//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);  

void setup() {  
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
}

void loop() {
  //正轉一圈
  if(digitalRead(BTN1) == HIGH){
    myStepper.step(100);
   
  }
  
  //倒轉一圈
  if(digitalRead(BTN2) == HIGH){
    myStepper.step(-100);
   
  }
}
