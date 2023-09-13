/**********************************************Macros Start*****************************************************/
#define Encoder_A 2
#define Encoder_B 3
#define b 0.9829
#define a 0.01705 // Adjust this value to control the amount of filtering.
/**********************************************Macros End*******************************************************/

double raw_count = 0;       // Record the raw count from the encoder.
double filtered_count = 0; // Record the filtered count from the encoder.

/***************************************Function Deceleration Start*********************************************/
void do_encoder_a(void);
void do_encoder_b(void);
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
  Serial.println(raw_count);
  Serial.print("Filtered Counts:\t");
  Serial.println(filtered_count);
}

/***************************************Function Definition Start********************************************/
void do_encoder_a(void) {

  if (digitalRead(Encoder_A) != digitalRead(Encoder_B)) {
    raw_count++;
  } else {
    raw_count--;
  }

  // Apply the low-pass filter.
  filtered_count = (a * filtered_count) + (b * raw_count);
}

void do_encoder_b(void) {

  if (digitalRead(Encoder_A) == digitalRead(Encoder_B)) {
    raw_count++;
  } else {
    raw_count--;
  }

  // Apply the low-pass filter.
  filtered_count = (a * filtered_count) + (b * raw_count);
}
/****************************************Function Definition End*********************************************/
