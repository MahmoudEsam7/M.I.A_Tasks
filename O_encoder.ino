/**********************************************Macros Start*****************************************************/
#define Encoder_A 2
#define Encoder_B 3
/**********************************************Macros End*******************************************************/
double count = 0; //record number of pulses received

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
  // put your main code here, to run repeatedly:
  Serial.print("Counts:\t");
  Serial.println(count);
}

/***************************************Function Definition Start********************************************/
void doencoder_A(void){
  if (digitalRead(Encoder_A) != digitalRead(Encoder_B))
  {
    count++;
  }else
  {
    count--;
  }
}

void doencoder_B(void){
  if (digitalRead(Encoder_A) == digitalRead(Encoder_B))
  {
    count++;
  }else
  {
    count--;
  }
}
/****************************************Function Definition End*********************************************/