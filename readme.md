# Arduino Sensor Control Project

This project demonstrates basic sensor interaction and control using an Arduino microcontroller. The sketch allows you to control an LED's behavior using multiple input sensors.

## Hardware Requirements

- Arduino board (Uno, Nano, or similar)
- Pushbutton
- Light Dependent Resistor (LDR)
- Potentiometer (10kΩ recommended)
- LED
- Resistors:
  - 220Ω resistor for the LED
  - 10kΩ pull-down resistor for the button
  - 10kΩ resistor for the LDR (to create voltage divider)
- Breadboard and jumper wires

## Circuit Connections

- **Button**: Connected to digital pin 2 (with pull-down resistor)
- **Light Sensor (LDR)**: Connected to analog pin A0 (as voltage divider)
- **Potentiometer**: Connected to analog pin A1
- **LED**: Connected to digital pin 3 (with current-limiting resistor)
- The built-in LED (LED_BUILTIN) is also used

## Functionality

The project demonstrates several fundamental Arduino concepts:

1. **Digital Input**: Reading button state
2. **Analog Input**: Reading values from light sensor and potentiometer
3. **PWM Output**: Controlling LED brightness
4. **Timing**: Non-blocking blink patterns using `millis()`
5. **Serial Communication**: Debugging via Serial Monitor

### Behavior

- **When Button is NOT Pressed**:
  - The LED blinks at a rate controlled by the potentiometer
  - Turning the potentiometer adjusts the blink interval from 50ms to 1000ms

- **When Button IS Pressed**:
  - The LED stays continuously ON (solid, no blinking)

- **Light Sensor Control**:
  - The brightness of the LED is controlled by the light sensor
  - Covering the light sensor (less light) increases the LED brightness
  - More ambient light decreases the LED brightness

## How to Use

1. Connect the components as described in the circuit connections
2. Upload the sketch to your Arduino board
3. Open the Serial Monitor (9600 baud) to see the sensor values
4. Interact with the sensors:
   - Press/release the button to toggle between blinking and solid modes
   - Turn the potentiometer to adjust the blink rate
   - Cover/uncover the light sensor to see brightness changes

## Code Structure

The code is organized in the standard Arduino setup/loop structure:

- **Pin Definitions**: Constants for pin assignments
- **Global Variables**: For timing, sensor values, and state tracking
- **Setup Function**: Initializes pins and serial communication
- **Loop Function**: Continuously reads sensors and controls the LED

## Debugging

The sketch includes serial output for debugging purposes, printing:
- Button state
- Light sensor value
- Potentiometer value 
- Calculated blink interval
- Current LED state

Monitor these values at 9600 baud to troubleshoot or better understand the behavior.

## Modifications and Extensions

Possible modifications to extend the project:
- Add additional sensors (temperature, motion, etc.)
- Implement different LED patterns
- Add multiple LEDs with different behaviors
- Use the potentiometer to control different parameters
- Add a buzzer for audio feedback

## License

This project is open source and available under the MIT License.
