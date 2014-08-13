
// based on SerialEvent
// created by Romilly Cocking
// http://www.rareschool.com
// and placed in the public domain

const int MAX = 6;
char *greetings[MAX] = {
"A stitch in time saves nine",
"Too many cooks spoil the broth",
"Fools seldom differ",
"Great minds think alike",
"Many a mickle makes a muckle",
"All that glitters is not Gold"};
boolean reply = false;

void setup() {
  // initialize serial:
  Serial.begin(9600);
}

void loop() {
  // print the string when a newline arrives:
  if (reply) {
    int index = (int) random(MAX);
    Serial.println(greetings[index]);
    reply = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char c = (char) Serial.read();
    if (c == '\n') {
      reply = true; 
    }  
  }
}


