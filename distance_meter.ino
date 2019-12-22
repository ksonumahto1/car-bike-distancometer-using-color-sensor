//Tutorial: https://www.electronoobs.com/eng_arduino_tut70.php
// TCS230 or TCS3200 pins wiring to Arduino
#define S1 4
#define S0 5
#define S3 6
#define S2 7
#define sensorOut 8

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int d = 0;
int c=0;
int c1;
int c2;
int c3;
int mystr;


void setup() {  
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);  
  // Setting frequency scaling to 20%  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);  
   // Begins serial communication 
  Serial.begin(9600);
}
void loop() {
  DstMtr();
}
void DstMtr() {  
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW); 
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  
   // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(blueFrequency);  
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenFrequency);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.println(blueFrequency);  

  // Checks the current detected color and prints
  // a message in the serial monitor
  if(redFrequency < greenFrequency && redFrequency < blueFrequency){
    c1 = 5;
    Serial.println(" - RED detected!");
    d +=c1;
    if(c==c1){
    d -= c;
    }
    c=c1;
  }
  else if(greenFrequency < redFrequency && greenFrequency < blueFrequency){
    c2 = 6;
    Serial.println(" - GREEN detected!");
    d +=c2;
    if(c==c2){
    d -= c;
    }
    c=c2;
  }
  else if(blueFrequency < redFrequency && blueFrequency < greenFrequency){
    c3 = 7;
    Serial.println(" - BLUE detected!");
    d +=c3;
    if(c==c3){
    d -= c;
    }
    c=c3;
  }
  Serial.write(d / 256); //Write the serial data
  Serial.write(d % 256);
  Serial.print("- distance = ");
  Serial.println(d);
  Serial.println(c);
  delay(50);
}
 
