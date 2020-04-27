/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
 Serial.begin(9600);

}


void loop() {
 
  int n = 100;
  long indVal[n];
  double avg = 0;
  for(int i=0;i<n;i++) {
    indVal[i] = analogRead(A0);
    avg += indVal[i];
    delay(1);
   }
   avg /= float(n);
   long total = 0;
   for(int i=0;i<n;i++) {
    total += (indVal[i] - avg)*(indVal[i] - avg);
   }
   float variance = total/float(n-1);
   float stDev = sqrt(variance);
   double stdError = stDev/sqrt(n);
  Serial.println(stdError);
 
          
}
