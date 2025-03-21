/*
  Arduino Sensor Control Sketch
  
  Hardware setup:
  - Button connected to digital pin 2
  - Light resistor (LDR) connected to analog pin 0
  - Potentiometer connected to analog pin 1
  - LED connected to digital pin 3
  - Built-in LED on pin LED_BUILTIN
  
  Functionality:
  - LED on pin 3 blinks at a rate controlled by potentiometer when button is NOT pressed
  - When button IS pressed, the LED on pin 3 stays solid ON (no blinking)
  - Covering the light sensor increases the brightness of the LED on pin 3
*/

// Pin definitions
const int BUTTON_PIN = 2;
const int LIGHT_SENSOR_PIN = A0;
const int POTENTIOMETER_PIN = A1;
const int LED_PIN = 3;

// Variables for timing
unsigned long previousMillis = 0;
int blinkInterval = 500;  // Default blink interval in milliseconds

// Variables for state
bool ledState = LOW;
int lightSensorValue = 0;
int potentiometerValue = 0;
bool buttonState = LOW;

void setup() {
  // Initialize pins
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  buttonState = digitalRead(BUTTON_PIN);
  lightSensorValue = analogRead(LIGHT_SENSOR_PIN);
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  
  // Map potentiometer value to blink interval (50ms to 1000ms)
  blinkInterval = map(potentiometerValue, 0, 1023, 50, 1000);

  // Calculate LED brightness based on light sensor
  // The sensor delivers values between 700-1023
  int brightness = map(1023 - lightSensorValue, 700, 1023, 0, 255);
  
  // Check button state to control LED behavior
  if (buttonState == HIGH) {
    // BUTTON PRESSED: LED ON PIN 3 STAYS SOLID ON (no blinking)
    analogWrite(LED_PIN, brightness);  // Turn LED on with brightness controlled by light sensor
  } else {
    // BUTTON NOT PRESSED: BLINK the LED at the rate determined by potentiometer
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      
      // Toggle LED state
      ledState = !ledState;
      
      if (ledState == HIGH) {
        // When LED is ON during blink cycle
        analogWrite(LED_PIN, brightness);
      } else {
        // When LED is OFF during blink cycle
        digitalWrite(LED_PIN, LOW);
      }
    }
  }
  
  // Small delay to stabilize readings
  delay(10);
  
  // Print debug information
  Serial.print("Button: ");
  Serial.print(buttonState);
  Serial.print(" | Light: ");
  Serial.print(lightSensorValue);
  Serial.print(" | Pot: ");
  Serial.print(potentiometerValue);
  Serial.print(" | Blink Interval: ");
  Serial.print(blinkInterval);
  Serial.print(" | LED State: ");
  Serial.println(ledState);
}