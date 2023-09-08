# Every Step Matter

## Code :
+ simple Code For Get Number Of Pulses From Optical Encoder Using Interrupt:
  
      pinMode(Encoder_A,INPUT_PULLUP);   
      pinMode(Encoder_B,INPUT_PULLUP);
      attachInterrupt(digitalPinToInterrupt(Encoder_A),doencoder_A,CHANGE);
      attachInterrupt(digitalPinToInterrupt(Encoder_B),doencoder_B,CHANGE);
+ The ISR :

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

+ Design of Low Pass Filter :

       Linear speed(m/s) = rpm.(3.14 * D)/60
       rpm = (0.5*60)/(3.14*0.4) = 23.873
       Max frequency = (rpm * ppr)/60 = (23.873*540)/60 = 214.857 Hz
       the cutoff frequency slightly less than the Max frequency of the signal and higher than the noise frequency.  

    
