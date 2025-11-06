// Automatic Light Control using LDR and Transistor
// Description: Turns on an LED in darkness and off in light using an LDR.
// Hardware: Arduino Uno + Photoresistor + 10k Resistor + NPN Transistor + LED

#define ldrPin A0    // Analog pin for photoresistor
#define ledPin 9     // Digital PWM pin for LED (via transistor base)

int lightValue = 0;
int threshold = 500; // Light threshold (tuned experimentally)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(ldrPin); // Read light level (0–1023)
  Serial.print("Light: ");
  Serial.println(lightValue);

  // If light level is low (darkness), turn LED ON
  if (lightValue < threshold) {
    digitalWrite(ledPin, HIGH);  // Turn ON light
  } else {
    digitalWrite(ledPin, LOW);   // Turn OFF light
  }

  delay(80); // 80 ms response time
}
