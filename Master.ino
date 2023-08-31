/*
 *      Author:Mahmoud Esam Ali
 *      Description : start I2C protocal communication, sending the state of 2 Push_Buttons 
 *      Date : 2023-Aug-19
 */

#include <Wire.h>
/***************************************************Macros Start***************************************************/
#define PB1 10
#define PB2 11
/****************************************************Macros End****************************************************/

/*********************************************Global Declaration Start*********************************************/
int BUTTON1 = 0;
int BUTTON2 = 0;
/**********************************************Global Declaration End**********************************************/

void setup()
{
  Wire.begin();
  pinMode(PB1, INPUT_PULLUP);
  pinMode(PB2, INPUT_PULLUP);
}

void loop()
{
   //start the communication with slave 6
   Wire.beginTransmission(10);
   while (digitalRead(PB1)==0); // to avoid bouncing
   BUTTON1 = digitalRead(PB1);
   while (digitalRead(PB2)==0); // to avoid bouncing
   BUTTON2 = digitalRead(PB2);
   // send data
   Wire.write(BUTTON1);
   Wire.write(BUTTON2);

   Wire.endTransmission();

}

