// Thermistor NTC 10K e LCD

#include <Thermistor.h> 
 
Thermistor temp(13);   
 
int ldr = 12; 
int valorldr = 0;
int temperatura = 0;  

void setup() {
  pinMode(ldr, INPUT); 
  Serial.begin(9600);   
  //delay(1000);  
}
void loop() {
  //Sensor de temperatura NTC
  int temperatura = temp.getTemp(); 
  Serial.print("Temperatura: "); 
  Serial.print(temperatura); 
  Serial.print("°C");

  //Sensor de luminusidade LDR  
   valorldr=analogRead(ldr);  
   Serial.print(" LDR = ");
   Serial.println(valorldr);             
   
  delay(1000);  
}
