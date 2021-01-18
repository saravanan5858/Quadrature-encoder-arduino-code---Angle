float pos;  //variable to calculate angle
volatile double Count = 0;   //volatile variable to count the detected digital pulse

void setup(){
        
        
                  
        pinMode(20, INPUT);  //encoder channel-A interrupt pin
        pinMode(21, INPUT);  //encoder channel-B interrupt pin    
        attachInterrupt(digitalPinToInterrupt(20), EncoderEvent, CHANGE); //interrupt function to call ISR function whenever the pulse is detected
       
        
        Serial.begin(9600);
                    
}    

void loop(){
     Serial.print("Angle :");
     
     Serial.println(pos);
     //Serial.println(Count);
     pos =  (Count/600)* 360;         //Encoder resolution is 600 PPR and 2400 CPR
   }  


void EncoderEvent() {                 //ISR function to count the encoder pulses
  if (digitalRead(20) == HIGH) {
    if (digitalRead(21) == LOW) {
      Count++;
    } 
    else if(digitalRead(21) == HIGH) {
      Count--;
    }}}
  
