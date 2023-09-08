/*
 *      Author:Mahmoud Esam Ali
 *      Description : 
 *      Date : 2023-Sep-4
 */

#include <Wire.h>

/************************************************Global Declaration Start***********************************************************/
const int MPU = 0x68; // MPU6050 I2C address
float GyroZ;
float yaw;
float GyroErrorZ , Offset_Z;
float dTime, currentTime, previousTime;
int c = 0;
/*************************************************Global Declaration End************************************************************/

void setup() {
  Serial.begin(19200);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);      
  
  // Configure Gyro Sensitivity 
  Wire.beginTransmission(MPU);
  Wire.write(0x1B);                   // Talk to the GYRO_CONFIG register (1B hex)
  Wire.write(0x08);                   // Set the register bits as 00001000 (500deg/s full scale)
  Wire.endTransmission(true);
  delay(20);
  
  // Call this function to get the IMU error value for your module
  Offset_Z = calculate_IMU_error();
  delay(20);
}
void loop() {
  // === Read gyroscope data === //
  previousTime = currentTime;        // Previous time is stored before the actual time read
  currentTime = millis();            // Current time actual time read
  dTime = (currentTime - previousTime) / 1000; // Divide by 1000 to get seconds
  Wire.beginTransmission(MPU);
  Wire.write(0x47); 
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 2);
  while(Wire.available() <2);  
   
  GyroZ = (Wire.read() << 8 | Wire.read()) / 65.5; // For a 500deg/s range we have to divide first the raw value by 65.5, according to the datasheet
  // Correct the output with the calculated error values
  GyroZ = GyroZ - Offset_Z;
  // Currently the raw values are in degrees per seconds, so we need to multiply by sendonds  to get the angle in degrees
  yaw =  yaw + GyroZ * dTime;
  
  Serial.print("Yaw:\t");
  Serial.println(yaw);
}
/***********************************************Function Definition Start***************************************************/
float calculate_IMU_error() {
  // we should place the IMU flat in order to get the proper values, so that we then can the correct values
  // Read gyro values 2000 times
  while (c < 3000) {
    Wire.beginTransmission(MPU);
    Wire.write(0x47);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 2, true);
    GyroZ = Wire.read() << 8 | Wire.read();
    // Sum all readings
    GyroErrorZ = GyroErrorZ + (GyroZ / 65.5);
    c++;
  }
  //Divide the sum by 2000 to get the error value
  GyroErrorZ = GyroErrorZ / 3000;
  
  return GyroErrorZ ;
}
/************************************************Function Definition End****************************************************/