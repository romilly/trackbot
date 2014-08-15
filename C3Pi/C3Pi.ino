/* CC Share Alike 3.0 quick2wire.com 2013
 */
// driver for C3Pi with Teensy 3.0
// for Teensy 3.0 pinouts see https://www.pjrc.com/teensy/card5a_rev5.pdf
// for motor control pin names see https://content.solarbotics.com/products/datasheets/solarbotics_l298_compact_motor_driver_kit.pdf


// Left side motor pins
const int L1  = 4;    // yellow, 
const int L2  = 5;    // orange, 
const int E12 = 6;    // blue, motor PWM
const int Right[] = { L1, L2, E12 };

// Right (from front of robot) side motor pins
const int L3  = 22;    // orange, 
const int L4  = 21;    // yellow, 
const int E34 = 20;    // blue, motor PWM
const int Left[] = {L3, L4, E34 };

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


void do_command(char x) {
  switch(x) {
    case 'd': dance(); break;
    case '!': flashOnboardLED(); break;
    case '.': brake(Left); brake(Right); break;
    case 'f': forwards(Left); forwards(Right);  speed(Left, 255); speed(Right, 255); break;
    case 'b': backwards(Left); backwards(Right); speed(Left, 255); speed(Right, 255); break;
    case 'l': forwards(Left); brake(Right); speed(Left, 255); speed(Right, 0); break;
    case 'r': brake(Left); forwards(Right); speed(Left, 0); speed(Right, 255); break;
    default: break;
  } 
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

void loop(){
  if (Serial.available()) {
    // get the new byte:
    char c = (char) Serial.read();
    do_command(c);
  }
}


void dance() {
  
 
  forwards(Left);
  fadeUpTo(Left, 255);
  
  backwards(Left);
  fadeUpTo(Left, 255);
  brake(Left);
  
  forwards(Right);
  fadeUpTo(Right, 255);

  backwards(Right);
  fadeUpTo(Right, 255);
  brake(Right);
  delay(200);
  
}




