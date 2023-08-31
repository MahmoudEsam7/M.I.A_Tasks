#include <Wire.h>
/****************************************************Macros Start**************************************************/
#define LeD 3
/*****************************************************Macros End***************************************************/

/*********************************************Global Declaration Start*********************************************/
int BUTTON1 =LOW;
int BUTTON2 =LOW;
/**********************************************Global Declaration End**********************************************/

/********************************************Function Declaration Strat********************************************/
void receiveEvent(int howMany);
/*********************************************Function Declaration End*********************************************/

void setup()
{
  Wire.begin(10);
  
  Wire.onReceive(receiveEvent); 
  pinMode(LeD, OUTPUT);
}

void loop()
{
  delay(100);
}
/*********************************************Function Definition Strat*********************************************/
void receiveEvent(int howMany){
// receive Data from Master 
BUTTON1 = Wire.read();
BUTTON2 = Wire.read();
  // check state of the 2 Push_Buttons
  if ((BUTTON1 == 0) && (BUTTON2==0) ){
  
      analogWrite(LeD,0);
      
  }
  else if((BUTTON1 == 1) && (BUTTON2==0)){

    analogWrite(LeD,128);
    Serial.println("Vector focused");
  }
  else if ((BUTTON1 == 0) && (BUTTON2==1)){

    analogWrite(LeD, 191);
    Serial.println("Vector distracted");
  }else
  {
    analogWrite(LeD, 255);
    Serial.println("Glitch");
  }
       
}
/**********************************************Function Definition End**********************************************/