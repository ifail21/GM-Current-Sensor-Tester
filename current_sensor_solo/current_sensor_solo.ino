#include "PWM.hpp"

const int zeroRef = 4146;
int Cal = 0;
PWM my_pwm(2); 
int sensorValue = 0;       
int Amps = 0;

void setup() {
    Serial.begin(115200);
    my_pwm.begin(true);
    Cal = ((zeroRef*2)-400);
}

void loop() {
  sensorValue = (my_pwm.getValue());
  Amps = map(sensorValue, 400, Cal, -60, 60);
  Serial.print("Amps = ");
  Serial.print(Amps);
  Serial.print("\t On-Time μs = ");
  Serial.println(sensorValue);
  delay(100);
}
  
