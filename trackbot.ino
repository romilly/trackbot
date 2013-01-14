/* CC Share Alike 3.0 quick2wire.com 2013
 */
// driver for trackbot
// for Arduino mini pro pinouts see http://arduino.cc/en/uploads/Main/Arduino-Pro-Mini-schematic.pdf
// for motor control pin names see https://content.solarbotics.com/products/datasheets/solarbotics_l298_compact_motor_driver_kit.pdf

// Right (from front of robot) side motor pins 
const int L4  = 3;    // yellow, d3
const int L3  = 4;    // orange, d4
const int E34 = 5;    // blue, motor PWM 

// Left side motor pins
const int L2  = 7;    // yellow, d7
const int L1  = 8;    // orange, d8
const int E12 = 9;    // blue, motor PWM

const int onboardLED = 13;

void flashOnboardLED() {
  digitalWrite(onboardLED, HIGH);
  delay(800);
  digitalWrite(onboardLED, LOW);
}

void flashForStartup() {
  pinMode(onboardLED, OUTPUT);
  flashOnboardLED();
  delay(200);
  flashOnboardLED();
}

void setup() {
  // digital pins
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  
  flashForStartup();
}

void loop() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  for (int pwm = 0; pwm < 256; pwm++) {
    analogWrite(E12, pwm);
    delay(10);
  }
  flashOnboardLED();
  delay(200);
}




