/*
 *      Author:Mahmoud Esam Ali
 *      Description :fuse data form two sensors without regard accuracy of each sensor and taking into consideration the physics of projectile to infer new information and fuse all this information   
 *      Date : 2023-Aug-14
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*********************************************Macros Start********************************************/

#define Initial_Velocity 30           //initial velocity
#define Initial_Angle 0.8028514559    //initial angle in rad 
#define a 9.8 //Gravity acceleration
#define accuracy_sys 96   //assume accuracy of system = 96%
#define accuarcy_pre 85.5 // accuracy_pre = (accuracy1 + accuracy2)/2  take the average  
/***********************************************Macros End********************************************/

/*************************************Functions prototype Start*************************************/
void weighted_average(float *sensor1, float *sensor2,float predict[], float accuracy1, float accuracy2) ;
void predict_step (void) ;
/*************************************Functions prototype End***************************************/

/**************************************Global Decleration Start***************************************/
float predict[10];
float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
float bno55[10] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
float accuracy1 = 79;   //accuracy of mpu6050
float accuracy2 = 92;   //accuracy of bno55
/***************************************Global Decleration End****************************************/
int main() {
  
  predict_step (); //call function which predict the system 
  
  weighted_average(mpu6050, bno55, predict, accuracy1, accuracy2); //call the function to fuse all data
  
  return 0;
}


/*********************************Functions Definition Start*******************************************/

//function to fuse the two sensors
void weighted_average(float sensor1[], float sensor2[],float predict[], float accuracy1, float accuracy2) {
  float fused_values[10]; // create array for output fused data
  float fused_values_pre[10]; //create an array for store data for sensors's data fused
  float weight1 = (accuracy1) / (accuracy1 + accuracy2 );
  float weight2 = (accuracy2) / (accuracy1 + accuracy2 );
  
  for (int i = 0; i < 10; i++) {
    fused_values_pre[i] = (sensor1[i] * weight1 + sensor2[i] * weight2 ) / (weight1 + weight2 );
    
  }
  
  float weight3 = (accuarcy_pre)/(accuarcy_pre + accuracy_sys);
  float weight4 = (accuracy_sys)/(accuarcy_pre + accuracy_sys);
  for (int i =0; i<10; i++) {
   fused_values[i] = (fused_values_pre[i]*weight3 + predict[i]*weight4  ) / ( weight3 + weight4); // take the average between the data from predict function and the data we have from fuse 2 sensors
  }
  
  printf("The fused values are: \n");   
  for (int i = 0; i < 10; i++) {
    printf("%f\n", fused_values[i]);
  }  

}
void predict_step (void)
{
  
  float Time=0; //time to calculate distance
  float Y_position;   
  for (int counter=0 ; counter<10; counter++ )
  {
    float V_final =(Initial_Velocity*sin(Initial_Angle)-(a*Time));
    float V_Initial = powf(Initial_Velocity * sin(Initial_Angle),2);
  
    Y_position = (V_Initial - (V_final*V_final))/(2*a) ;
    *(predict+counter) = Y_position ;
    Time+=0.5;
  }
}
/*********************************Functions Definition End*******************************************/