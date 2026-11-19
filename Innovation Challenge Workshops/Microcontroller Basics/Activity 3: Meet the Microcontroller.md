# Meet the Microcontroller
Now you will be programming the circuit in either Arduino IDE or the PlatformIO extension in VS Code. 

When you open a blank sketch/file in Arduino IDE you will see the following skeleton: 
```
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
```
In PlatformIO you will see some additional sample code which you can delete and just remain with the same code skeleton as above with the exception to leave `#include <Arduino.h>` above `void setup()`. 

## Objective 

## Useful Code Syntax and Functions
- Single line comments: `// comment`.
- Multi-line comments: `/* ... /*`.
- Every line of code must end with a semicolon `;`.
- Group blocks of code inside curly brackets `{}`.
- Use `const int` for fixed pin numbers and standard types like `int`, `float`, `bool`, and `unsigned long` for changing values.
- To set the pin as an input or output call `pinMode(pin, INPUT)` or `pinMode(pin, OUTPUT)`.
- Use `digitalWrite(pin, HIGH)` or `digitalWrite(pin, LOW)` to send voltage (eg. HIGH turns an LED on and LOW turns an LED off).
- Use `digitalRead(pin)` to check the pin state.
- Use `delay(ms)` to pause the program for a set amount of milliseconds (eg. `delay(1000)` pauses the program for one second).
- Use `Serial.begin(9600)` in `void setup()` to start communication with your computer. 9600 is the baud rate for an Arduino Uno is 9600 but an ESP32 microcontroller would have a baud rate of 115200. The baud rate specified in the code and the baud rate selected in the Serial Monitor must match for data to be displayed correctly.
-  To display information use `Serial.print()` and `Serial.println()` (`Serial.println()` prints the next displayed information on a new line). 

## Variable Definitions 
Variable definitions sit above `void setup()` as they declare pins that are used and other variables that will be used.

The pins that are used for this circuit are 2 and 3. You would declare them as the following: 
```
// Definitions
const int buttonPin = 3;
const int ledPin = 2;
```
## Setup
The setup function `void setup()` runs once every time the code is uploaded to the microcontroller and sets pin modes, starts communication, initializes hardware, and sets initial values. 

You can paste the following setup that will be used for this program: 
```
// Setup
pinMode(buttonPin, INPUT); // sets button pin as an input
pinMode(ledPin, OUTPUT); // sets led pin as an output
```

## Loop 
The loop function `void loop()` runs the code inside continuously and repeats. 
