//I initially copied the code from https://create.arduino.cc/projecthub/TheGadgetBoy/ds18b20-digital-temperature-sensor-and-arduino-9cc806
//If you go and see the code which is displayed on the site, you will notice that it is different. This is because I have modified it according to my expectations.

#include <OneWire.h>  //Libraries to be included     //I searched the libraries on google
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5   //ONE_WIRE_BUS will take the input from data_pin 5

OneWire oneWire(ONE_WIRE_BUS); // Setup a oneWire instance to communicate with any OneWire devices 

DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature.  

 float Celcius=0;         //Set initial temperature unit to 0
 
  
void setup(void)
{
  Serial.begin(9600);                       //All the setup is enclosed in this method
  sensors.begin();
  Serial.print("Time     "); 
  Serial.println("Celsius   "); 
  
}

void loop(void)
{ 
  long timeNow = millis();          //Used millis() which I learned in this class to display time.
  int curr = timeNow/1000;          //convert time to seconds
  String t = String(curr);        
  sensors.requestTemperatures();       //This requests the temperature from the library
  delay(1000);
  Celcius=sensors.getTempCByIndex(0);     //We get the temperature in Celsius
  String c = String(Celcius);              //To make it easier to read while it prints data out.
  Serial.print(t + "        ");
  Serial.println(c);
  
}
