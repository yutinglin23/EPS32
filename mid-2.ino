#include <Servo.h>  //匯入函式庫
#include "SSD1306Wire.h"
SSD1306Wire display(0x3c,21,22);
Servo myservo;  // 建立伺服馬達控制

//const int servoPin = 13;  //用常態變數設定pin腳位，與之前define方式差不多
int pos=1; //角度初始在中間，設定為90度

const int  Button1_Pin = 14; 


void setup() {
  Serial.begin(115200);//序列阜連線速率(鮑率)
  display.init();
  display.flipScreenVertically();
  display.clear();
 // myservo.attach(servoPin);  // 將伺服馬達連接的GPIO pin連接伺服物件
  //myservo.write(90);  //角度初始在中間，設定為90度

   pinMode(Button1_Pin, INPUT);
   randomSeed(analogRead(0));
}

void loop() {

  //Player 1
  if(digitalRead(Button1_Pin) == HIGH ){
   pos = random(2,360);
   Serial.println(pos);
    delay(1000);
   
  }
  if(pos<=45&&pos>1){
    display.setFont(ArialMT_Plain_24);
    display.drawString(0,16,"1_Rice");
    display.display();
  }
    else if(pos<=90&&pos>45){
    display.setFont(ArialMT_Plain_24);
    display.drawString(0,16,"2_Noodle");
    display.display();
  }
     else if(pos<=135&&pos>90){
    display.setFont(ArialMT_Plain_24);
    display.drawString(0,16,"3_Burger");
    display.display();
  }
     else if(pos<=180&&pos>135){
    display.setFont(ArialMT_Plain_24);
    display.drawString(0,16,"4_Chicken");
    display.display();
  }
   else if(pos<=225&&pos>180){
    display.setFont(ArialMT_Plain_24);
    display.drawString(0,16,"5_Ricebug");
    display.display();
  }
     else if(pos<=270&&pos>225){
    display.setFont(ArialMT_Plain_24);
    display.drawString(0,16,"6_Pizza");
    display.display();
  }
     else if(pos<=315&&pos>270){
    display.setFont(ArialMT_Plain_24);
    display.drawString(0,16,"7_Hotpot");
    display.display();
  }
       else if(pos<=360&&pos>315){
    display.setFont(ArialMT_Plain_24);
    display.drawString(0,16,"8_Dumpling");
    display.display();
  }
  
    else if(pos==1){
    display.setFont(ArialMT_Plain_24);
    display.drawString(0,16,"Eat what");
    display.display();
  }
  display.clear();
  //myservo.write(pos);
  
}
