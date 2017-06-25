int LedPin = 16;

void setup() { 
  pinMode(LedPin, OUTPUT);
}

void loop() {
  digitalWrite(LedPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(LedPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second  
}
