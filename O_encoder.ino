/**********************************************Macros Start*****************************************************/
#define Encoder_A 2
#define Encoder_B 3
#define input_weight 0.731
#define out_weight 0.462
/**********************************************Macros End*******************************************************/
double count = 0; //record number of pulses received
unsigned int input_A[2] {0,0};
unsigned int input_B[2] {0,0};
unsigned int out_A[2] {0,0};
unsigned int out_B[2] {0,0};

/***************************************Function Deceleration Start*********************************************/
void doencoder_A(void);
void doencoder_B(void);
/***************************************F*unction Deceleration End**********************************************/

void setup() {
  
  Serial.begin(9600);
  pinMode(Encoder_A,INPUT_PULLUP);   
  pinMode(Encoder_B,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Encoder_A),doencoder_A,CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder_B),doencoder_B,CHANGE);

}

void loop() {
  
  //low pass filter
  input_A[1] = digitalRead(Encoder_A);
  input_B[1] = digitalRead(Encoder_B);
  out_A[1]   = out_weight*out_A[0] + input_weight*(input_A[1]+input_A[0]);
  out_B[1]   = out_weight*out_B[0] + input_weight*(input_B[1]+input_B[0]);
  //update 
  input_A[0] = input_A[1];
  input_B[0] = input_B[1];
  out_A[0]   = out_A[1];
  out_B[0]   = out_B[1];
  delay(20);
  Serial.print("Counts:\t");
  Serial.println(count);
}

/***************************************Function Definition Start********************************************/
void doencoder_A(void){

  if (out_A[1] != out_B[1])
  {
    count++;
  }else
  {
    count--;
  }
}

void doencoder_B(void){
  if (out_A[1] == out_B[1])
  {
    count++;
  }else
  {
    count--;
  }
}
/****************************************Function Definition End*********************************************/
