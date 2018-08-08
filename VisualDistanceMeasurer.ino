/*Project: Visual Distance Measurer*/
//pins to be used:
int trig=5;
int echo=6;

//variables for HC-sr04
float distance;                                                           //Distance to the target
float speedOfSound=340.;                                                  //Speed of sound in m/s

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);                                                     //Start the serial monitor
  pinMode(trig,OUTPUT);                                                   //trig pin set to output mode
  pinMode(echo,INPUT);                                                    //Echo pin set to input mode

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trig,LOW);                                                 //Start with a low signal
  delayMicroseconds(2000);                                                //Let the signal settle. Waveform: __
  digitalWrite(trig,HIGH);                                                //High Signal Starts. Waveform: __--
  delayMicroseconds(15);                                                  //Let the high signal settle
  digitalWrite(trig,LOW);                                                 //Pass the low signal to complete the ping. Waveform: __--__
  delayMicroseconds(20);                                                  //Let the signal settle again

  float pingTime=pulseIn(echo,HIGH);                                      //Detects the pulse timing at the echo pin in microseconds
  speedOfSound=340.0/25400.0;                                             //Converts m/s to inches/microseconds
  distance=(speedOfSound*pingTime)/2.0;                                   //converts and gives the distance in inches
  Serial.println(distance);                                               //prints the distance on the serial monitor  
  delay(100);                                                             //just to slow down things a little
  
}
