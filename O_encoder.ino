/**********************************************Macros Start*****************************************************/
#define Encoder_A 2
#define Encoder_B 3
#define b 0.9956
#define a 0.004389 // Adjust this value to control the amount of filtering.
/**********************************************Macros End*******************************************************/

double raw_count[2] = {0,0}; // Record the raw count from the encoder.
double filtered_count[2] = {0,0}; // Record the filtered count from the encoder.

/***************************************Function Deceleration Start*********************************************/
void do_encoder_a(void);
void do_encoder_b(void);
void low_pass_filter(void);
/***************************************Function Deceleration End**********************************************/

void setup() {

  Serial.begin(9600);
  pinMode(Encoder_A, INPUT_PULLUP);
  pinMode(Encoder_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Encoder_A), do_encoder_a, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder_B), do_encoder_b, CHANGE);

}

void loop() {
  // Put your main code here, to run repeatedly:
  Serial.print("Raw Counts:\t");
  Serial.println(raw_count[1]);
  Serial.print("Filtered Counts:\t");
  Serial.println(filtered_count[1]);
}

/***************************************Function Definition Start********************************************/
void do_encoder_a(void) {

  if (digitalRead(Encoder_A) != digitalRead(Encoder_B)) {
    raw_count[1]+= 1;
  } else {
    raw_count[1]-= 1;
  }

  // Apply the low-pass filter.
  low_pass_filter();
}

void do_encoder_b(void) {

  if (digitalRead(Encoder_A) == digitalRead(Encoder_B)) {
    raw_count[1]+= 1;
  } else {
    raw_count[1]-= 1;
  }

  // Apply the low-pass filter.
  low_pass_filter();
}

void low_pass_filter(void)
{
    filtered_count[1] = (a * filtered_count[0]) + (b *(raw_count[1] + raw_count[0]));
    filtered_count[0]= filtered_count[1];
    raw_count[0] = raw_count[1];  
}
  
/****************************************Function Definition End*********************************************/
