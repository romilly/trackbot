/* CC Share Alike 3.0 quick2wire.com 2013
 */
// driver for trackbot
// for Arduino mini pro pinouts see http://arduino.cc/en/uploads/Main/Arduino-Pro-Mini-schematic.pdf
// for motor control pin names see https://content.solarbotics.com/products/datasheets/solarbotics_l298_compact_motor_driver_kit.pdf

// Right (from front of robot) side motor pins 
const int L4  = 3;    // yellow, d3
const int L3  = 4;    // orange, d4
const int E34 = 5;    // blue, motor PWM 
const int Left[] = {L4, L3, E34 };

// Left side motor pins
const int L2  = 7;    // yellow, d7
const int L1  = 8;    // orange, d8
const int E12 = 9;    // blue, motor PWM
const int Right[] = { L2, L1, E12 };

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

void forwards(const int pins[]) {
  digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], HIGH);
}

void backwards(const int pins[]) {
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[1], LOW);
}

void brake(const int pins[]) {
  digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], LOW);
}
void speed(const int pins[], int pwmLevel) {
  analogWrite(pins[2], pwmLevel);
}

void fadeUpTo(const int pins[], int maxLevel) {
  for (int pwm = 0; pwm < maxLevel; pwm++) {
    speed(pins, pwm);
    delay(10);
  }
}


void loop() {
  forwards(Left);
  fadeUpTo(Left, 64);
  
  backwards(Left);
  fadeUpTo(Left, 64);
  brake(Left);
  
  forwards(Right);
  fadeUpTo(Right, 64);

  backwards(Right);
  fadeUpTo(Right, 64);
  brake(Right);
  
  flashOnboardLED();
  delay(200);
}




