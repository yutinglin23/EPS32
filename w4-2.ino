#include <Servo.h>  //匯入函式庫
#define LED_Pin 26;
Servo myservo;  // 建立伺服馬達控制
bool win=1;
const int servoPin = 13;  //用常態變數設定pin腳位，與之前define方式差不多
int pos = 90; //角度初始在中間，設定為90度

const int Button1_Pin = 12, Button2_Pin = 14; //紀錄兩按鈕腳位
bool btn1_Pressed = false, btn2_Pressed = false;  //紀錄兩按鈕按壓狀態

void setup() {
  Serial.begin(115200);//序列阜連線速率(鮑率)
  
  myservo.attach(servoPin);  // 將伺服馬達連接的GPIO pin連接伺服物件
  myservo.write(90);  //角度初始在中間，設定為90度
   pinMode(26,OUTPUT);
   pinMode(Button1_Pin, INPUT);
   pinMode(Button2_Pin, INPUT);
   
}

void loop() {
  if(win==1){
  //Player 1
  if(digitalRead(Button1_Pin) == HIGH && btn1_Pressed == false){
    btn1_Pressed = true;
    pos += 5; //角度加五度   
  }
  else if(digitalRead(Button1_Pin) == LOW && btn1_Pressed == true){
    btn1_Pressed = false;
  }

  //Player 2
  if(digitalRead(Button2_Pin) == HIGH && btn2_Pressed == false){
    btn2_Pressed = true;
    pos -= 5; //角度減五度
  }
  else if(digitalRead(Button2_Pin) == LOW && btn2_Pressed == true){
    btn2_Pressed = false;
  }
  Serial.println(pos);
  myservo.write(pos); //設定角度
  }
  if(pos==180||pos==0){
      win=0;
      digitalWrite(26,HIGH);
      delay(1000);
      }
 if(digitalRead(Button1_Pin) == HIGH && digitalRead(Button2_Pin) == HIGH){
    digitalWrite(26,LOW);
    pos = 90;
    myservo.write(pos);
    win=1;
  }
  
}
