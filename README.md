# **Precise Self-Localization**
## Code :
+ MPU6050 using I2c protocal to communicate, so we first Start communication with MPU6050 // MPU=0x68 :
  	
  	Wire.begin();
        Wire.beginTransmission(MPU);      
        Wire.write(0x6B); 
        Wire.write(0x00);                 
        Wire.endTransmission(true); 
+ Then i Configure Gyro Sensitivity :

	Wire.beginTransmission(MPU);
  	Wire.write(0x1B);
  	Wire.write(0x08);
        Wire.endTransmission(true);
        delay(20);
+ I Read Gyro data :

	 previousTime = currentTime; 
        currentTime = millis();            // Current time actual time read
        dTime = (currentTime - previousTime) / 1000; 
        Wire.beginTransmission(MPU);
        Wire.write(0x47); 
        Wire.endTransmission(false);
        Wire.requestFrom(MPU, 2);
        while(Wire.available() <2); 
        GyroZ = (Wire.read() << 8 | Wire.read()) / 65.5; // For a 500deg/s range we have to divide first the raw value by 65.5
+ To Calculate Yaw We Need to Integrate The Raw Data From Gyro :
  	
  	yaw =  yaw + GyroZ * dTime;
         
+ We Need to Calculate the offset of MPU6050:
	
       we should place the IMU flat in order to get the proper values, so that we then can the correct values, Read gyro values 2000 times and       getthe average


     




