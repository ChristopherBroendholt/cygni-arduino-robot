# cygni-arduino-robot
Cygni konsulentmøde der handler om arduino robot programmering. I dette tilfælde en line follower robot. 

## Setup Arduino workspace
1) VS code can be used as ide for programming Arduinos but its a bit of a hassle to setup: [guide](https://www.circuitstate.com/wp-content/cache/all/tutorials/how-to-use-vs-code-for-creating-and-uploading-arduino-sketches/index.html)
2) But, arduino have their own IDE that can be found [here](https://www.arduino.cc/en/software)


## Code structure
All arduino sketches (programs) are created using .ino file. This will be the entry point for the program. As the arduino is programmed using a version of c++. Therefore packages containing header and implementation files can be used. These files needs to be located in a folder called src.

```
file structure:

- sketch
    - src
        - class.h
        - class.cpp
    - myFirstSketch.ino
```

## Code examples

I/O pins
Pins are used as the interface for all i/o operations. It is common de use a macro to define a pin.
```cpp
#define LED_PIN 2 //Macro, now LED_PIN will always have the value 2
```

Arduino also requires a pin to have a mode (pinMode)
```cpp
void setup(){
    pinMode(LED_PIN, OUTPUT);   //This sets the LED_PIN's mode to be an output, meaning the pin can send data/voltage out.

    pinMode(SENSOR_PIN, INPUT); //This sets the SENSOR_PINS's mode to be an input, meaning the pin is ready to read data/voltage.
}
```

There are two types of pins analog and digital pins. Analog pins can read a value between 0 and 1023 where digital pins can only read HIGH or LOW. Some digital pins can output a PWM (pulse width modulation) signal with a range from 0 - 255.
```cpp
void loop(){
    bool sensor_value = digitalRead(SENSOR_PIN); //This will read the SENSOR_PIN and get a value of either HIGH or LOW
    
    int sensor_value = analogRead(SENSOR_PIN); //This will read the SENSOR_PIN and get a value from 0 - 1023

    digitalWrite(LED_PIN, HIGH) //This will set the LED_PIN to high (1023)

    analogWrite(LED_PIN, 127) //This will set the LED_PIN to a value of 127 (1)
}
```

(1) Because the max value is 255 and 127 is half of that, the pulse width modulation will only send a voltage half the time, resulting in the LED being lit with half intesity. 

Because the execution of the code is triggered in a loop, variables that needs to be saved between loops needs to be global. This is done simply by placing the variable outside the loop() and setup() functions.

```cpp
int counter = 0;

void loop(){
    counter++;
}
```

Serial printing is a way to send messages over the USB port to the terminal on your pc.
Serial communication uses a BAUD rate usually it is set to 9600 if the data that is being send is small. 
Different boards can also communicate together using Serial communication, but that is a bit more advanced.
```cpp
void setup(){
    Serial.begin(9600); //This sets the serial communication with a baud rate of 9600

}

void loop(){
    Serial.print("HELLO "); //This prints "HELLO " to the terminal
    Serial.println("WORLD"); //This prints "WORLD" to the terminal and adds a new line flag.
}
``` 

An arduino has an internal clock that starts running when the arduino starts. It counts in milliseconds. The clock can be accesed using millis()
```cpp

unsigned long time_since_start = 0;
void loop(){
    time_since_start = millis();
}
```