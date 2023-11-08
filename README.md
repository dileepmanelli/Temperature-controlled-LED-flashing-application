# Temperature-controlled-LED-flashing-application
This Arduino project demonstrates temperature-controlled LED flashing using an LM35 temperature sensor and an Arduino Uno. The onboard LED (pin 13) flashes at different rates based on the temperature read from the LM35 sensor. This project uses hardware timer interrupts for precise timing without relying on millis() or delay() functions.

# Features
Reads temperature from an LM35 sensor and converts it to Celsius.
Controls the LED flashing rate based on the temperature:
If temperature is below 30°C, LED flashes quickly (250 ms interval).
If temperature is 30°C or higher, LED flashes slowly (500 ms interval).
Utilizes Timer1 hardware interrupts for accurate timing.
# Components Used
Arduino Uno
LM35 Temperature Sensor
Onboard LED (Pin 13)
Necessary connections and wiring.
# How It Works
The code initializes Timer1 in CTC mode for precise timing.
It reads temperature from the LM35 sensor.
Depending on the temperature, it sets the LED flashing interval.
The onboard LED flashes according to the set interval using Timer1 interrupts.
# Instructions
Set up your hardware connections.
Upload the code to your Arduino Uno.
Observe the LED flashing pattern based on the temperature.
# Code Description
setup() initializes the LED pin and Timer1.
loop() reads LM35 sensor, sets the LED flashing interval based on temperature.
initializeTimer() configures Timer1 in CTC mode.
setTimerInterval() sets the timer interval based on the temperature condition.
ISR(TIMER1_COMPA_vect) is the Timer1 interrupt handler to control LED flashing.
# Author
[DILEEP MANELLI]
[dileepmanelli@gmail.com]


Acknowledgments
Arduino community and libraries.
