
// Greendzine Internship Assignment
// Dileep Manelli

#include <avr/interrupt.h>  //  library to handle the timing without using millis() or delay().

const int lm35Pin = A0;  // Analog pin for LM35 temperature sensor
const int ledPin = 13;   // Onboard LED on Arduino Uno

volatile int temperatureC;  // Store the temperature reading in Celsius
volatile bool ledState = LOW;  // Store the current state of the LED

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
  initializeTimer(); // The initializeTimer() function configures Timer1 to run in CTC mode and sets the prescaler to 8 for a 1ms resolution.
}

void loop() {
  // Read the LM35 temperature sensor
  int sensorValue = analogRead(lm35Pin); // Here analog input reading of temperature
  temperatureC = (sensorValue / 1024.0) * 500.0;  // Convert sensor reading to Celsius

  if (temperatureC < 30) {
    setTimerInterval(250);  // Set the timer interval to 250 ms for low temperature #Depending on the temperature condition, we set the timer interval using the setTimerInterval() function.
  } else {
    setTimerInterval(500);  // Set the timer interval to 500 ms for high temperature
  }
}

void initializeTimer() {
  cli();  // Disable interrupts

  // Set Timer1 to CTC (Clear Timer on Compare Match) mode
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 0x03E8;  // 1000 for 1ms when using a 16 MHz clock
  TCCR1B |= (1 << WGM12);  // Configure Timer1 for CTC mode
  TCCR1B |= (1 << CS11);  // Set prescaler to 8
  TIMSK1 |= (1 << OCIE1A);  // Enable Timer1 Compare A interrupt

  sei();  // Enable interrupts
}

void setTimerInterval(int interval) {
  // Calculate and set the compare value for Timer1 to change the interval
  int compareValue = (interval * 2) - 1;
  OCR1A = compareValue;
}

ISR(TIMER1_COMPA_vect) {
  // Timer1 Compare A interrupt handler
  ledState = !ledState; //This routine toggles the ledState variable between LOW and HIGH, effectively turning the LED on and off.
  digitalWrite(ledPin, ledState); // It writes the ledState value to the onboard LED (ledPin) using digitalWrite().
}
