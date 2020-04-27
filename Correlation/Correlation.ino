void setup() {

  Serial.begin(9600);

  float x[] = {1.2,2.2,3.2,4.2,5.2,6.2,7.2,8.2,9.2,0};
  float y[] = {0,9,8,7,6,5,4,3,2,1}; 
  double avg1 = 0, sum1 = 0;
  double avg2 = 0, sum2 = 0;
  
  for(int i=0;i<10;i++) {     //Find the average of both of the arrays.
    sum1 += x[i];
    sum2 += y[i];
    delay(1);
  }
  avg1 = sum1/10;
  avg2 = sum2/10;
  
  double total1 = 0;
  double total2 = 0;

  for(int i=0;i<10;i++) {                      //Step 1 for finding the Variance
    total1 += (x[i] - avg1)*(x[i] - avg1);
    total2 += (y[i] - avg2)*(y[i] - avg2);
  }

  double var1 = total1 /= 9.0;                   //This is how you find Variance
  double var2 = total2 /= 9.0;

  double stDevX = sqrt(var1);                   //Standard deviation is sqrt of the variance
  double stDevY = sqrt(var2);

  double cXY = 0;                               //Correlation found which should be between -1 and 1. 
  for(int i=0;i<9;i++) {
    cXY += ((x[i] - avg1)*(y[i] - avg2))/(stDevX*stDevY);
  }
  cXY *= 1.0/9;

Serial.print("X mean: ");
Serial.print(avg1);
Serial.print("   Y mean: ");
Serial.print(avg2);
Serial.print("   STD of X: ");
Serial.print(stDevX);
Serial.print("   STD of Y: ");
Serial.println(stDevY);
Serial.print("   Cxy is: ");
Serial.print(cXY);
delay(100);

}

void loop() {
  
}
