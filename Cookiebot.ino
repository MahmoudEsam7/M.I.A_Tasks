/*
 *      Author:Mahmoud Esam Ali
 *      Description : Localize the Cookie bot using 4 ultrasonic sensors    
 *      Date : 2023-Aug-19
 */

// assume 5cm between the center of the cookie bot and the sensors
// assume the robot start from Origin (0,0)

/****************************************************Macros Start**************************************************/
// sensor at angle 180
#define SENSOR_1_ECHO 10    
#define SENSOR_1_TRIGG 2
// sensor at angle 0
#define SENSOR_2_ECHO 11
#define SENSOR_2_TRIGG 3
// sensor at angle 270
#define SENSOR_3_ECHO 12
#define SENSOR_3_TRIGG 4
// sensor at angle 90
#define SENSOR_4_ECHO 13
#define SENSOR_4_TRIGG 5
/****************************************************Macros End****************************************************/

/*********************************************Global Declaration Start*********************************************/
float distance_1;  //SENSOR_1
float distance_2;  //SENSOR_2
float distance_3;  //SENSOR_3
float distance_4;  //SENSOR_4
/**********************************************Global Declaration End**********************************************/

/********************************************Function Declaration Strat********************************************/
int get_distance(int sensor_pin_Trigg,int sensor_pin_Echo);
void get_position();
/*********************************************Function Declaration End*********************************************/

void setup() {
  // Set the sensor pins 
  pinMode(SENSOR_1_TRIGG, OUTPUT);
  pinMode(SENSOR_1_ECHO, INPUT);

  pinMode(SENSOR_2_TRIGG, OUTPUT);
  pinMode(SENSOR_2_ECHO, INPUT);

  pinMode(SENSOR_3_TRIGG, OUTPUT);
  pinMode(SENSOR_3_ECHO, INPUT);

  pinMode(SENSOR_4_TRIGG, OUTPUT);
  pinMode(SENSOR_4_ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Get the position of the cookie bot
  get_position();

  // Wait for a 10 msec
  delay(10);
}
  
/********************************************Function Definition Strat********************************************/
  // Function to calculate the distance to a sensor
int get_distance(int sensor_pin_Trigg,int sensor_pin_Echo) {
  // Send out a sound wave
  digitalWrite(sensor_pin_Trigg, HIGH);
  delayMicroseconds(2);
  digitalWrite(sensor_pin_Trigg, LOW);

  // Measure the time it takes for the wave to return
  long duration = pulseIn(sensor_pin_Echo, HIGH);

  // Calculate the distance
  return duration * 0.034 / 2;
}

// Function to calculate the position of the cookie bot
void get_position() {
  float x_cookie_bot , y_cookie_bot;
  float x_shrink_ray_gun , y_shrink_ray_gun;
  // Get the distances to the sensors
  distance_1 = get_distance(SENSOR_1_TRIGG,SENSOR_1_ECHO) + 0.05; // 0.05 because my assumption at the top of the code
  distance_2 = get_distance(SENSOR_2_TRIGG,SENSOR_2_ECHO) + 0.05; 
  distance_3 = get_distance(SENSOR_3_TRIGG,SENSOR_3_ECHO) + 0.05; 
  distance_4 = get_distance(SENSOR_4_TRIGG,SENSOR_4_ECHO) + 0.05; 

  // Calculate the position of the cookie bot and the shrink ray gun
  // as we assume the robot start it's motion from the origin, so we have 3 Scenarios * the Gun at angle 90 respect to the robot * the Gun at angle 0 respect to the robot * the Gun is out of range respect to the robot
  
  // case one the "shrink ray gun" is at the top of the robot
  if ((distance_3 + distance_4) < 6)
  {
    x_cookie_bot = distance_1;
    y_cookie_bot = distance_3; 

    x_shrink_ray_gun = distance_1;
    y_shrink_ray_gun = distance_3 + distance_4; 
  }else if ((distance_3 + distance_4) < 5) { // "shrink ray gun" is on the right 
    x_cookie_bot = distance_1;  
    y_cookie_bot = distance_3;

    x_shrink_ray_gun = distance_1 + distance_2;
    y_shrink_ray_gun = distance_3;
  }else {
    x_cookie_bot = distance_1;
    y_cookie_bot = distance_3;

    x_shrink_ray_gun = -1;     // -1 if we do not see the Gun
    y_shrink_ray_gun = -1;    
  }

  // Print the position of the cookie bot and the shrink ray gun
  Serial.println("(X_Robot, Y_Robot) = " + String(x_cookie_bot) + ", " + String(y_cookie_bot));
  Serial.println("(X_Gun, Y_Gun)     = " + String(x_shrink_ray_gun) + ", " + String(y_shrink_ray_gun));
}

/*********************************************Function Definition End*********************************************/