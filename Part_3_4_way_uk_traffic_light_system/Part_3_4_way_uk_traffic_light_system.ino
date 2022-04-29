/* Disclaimer
 * This code is written for an Arduino Nano and has been tested on am Arduino Nano clone.
 * The code may work on other boards but has not been tested on them.
 * 
 * 
 * The Nano will sit on a sensor shield which makes it easier to access the Input / outputs. 
 * And supply the power required for the project.
 * You will also need 4 Red leds, 4 Amber / Yellow leds, and 4 Red leds.
 * You will also required 12 220ohm or 330 ohm resistors to put in series with each led.
 * A suitable power supply for powering the Arduino Nano between 7 - 12 volts. The shield has 
 * an on board voltage regulator to supply the correct power to the Arduino.
 * 
 * We will not be usings pins 1 and 2 in this project to avoid issues that can arise with  reprogramming
 * the Nano in future as they are used for the USB rx / tx as well by the Arduino.
 */

//Setup the various variables names used in the sketch we will separate the leds into 4 banks.

/*
 * These 9 leds have the positive lead / long lead on led go to the pins marked S on the shield
 * and the negative / short lead connected to the resistor goes to the pin marked G.
 */


//Bank 1 leds
const int redBank1 = 3;       
const int amberBank1 = 4;     
const int greenBank1 = 5;

//Bank 1A leds
const int redBank1a = 6;
const int amberBank1a = 7;
const int greenBank1a = 8;

//Bank 2 leds
const int redBank2 = 9;
const int amberBank2 = 10;
const int greenBank2 = 11;

/*
 * These 3 leds are being put on the anolog pins for easy wiring.
 * These 3 leds have the positive lead / long lead on led go to the pins marked S on the shield
 * and the negative / short lead connected to the resistor goes to the pin marked G.
 */

//Bank 2A leds
const int redBank2a = A0;      
const int amberBank2a = A1;
const int greenBank2a = A2;

/* Variables for the timing delays. I am going to use the delay() function for this code because this 
 * sketch has no interrupts. If it did we would use the millis() function with a for loop for the delays.
 * For this example i will setup 3 different time variables for 3 seconds, 19 seconds , and 25 seconds
 */

 const int shortDelay = 2000;     
 const int mediumDelay = 9000;
 const int longDelay = 15000;

 // That completes the variables i could have used #define also however that can cause issue sometimes.

void setup() {
  // We now need to setup all the pins as output using pinMode.

  pinMode(redBank1, OUTPUT);
  pinMode(amberBank1, OUTPUT);
  pinMode(greenBank1, OUTPUT);

  pinMode(redBank1a, OUTPUT);
  pinMode(amberBank1a, OUTPUT);
  pinMode(greenBank1a, OUTPUT);

  pinMode(redBank2, OUTPUT);
  pinMode(amberBank2, OUTPUT);
  pinMode(greenBank2, OUTPUT);

  pinMode(redBank2a, OUTPUT);
  pinMode(amberBank2a, OUTPUT);
  pinMode(greenBank2a, OUTPUT);

}

/*
 * Each of the below 6 functions control a single phase within the traffic light sequence and will 
 * move one line at a time until the end of the function. Then it will return to the void loop for 
 * the next function call
 */

void red1(){
  digitalWrite(redBank1, HIGH);               //red on for 2 seconds
  digitalWrite(amberBank1, LOW);              //amber off this needs to be done due to the final call in void amber1()
  
  digitalWrite(redBank1a, HIGH);
  digitalWrite(amberBank1a, LOW);

  digitalWrite(redBank2, HIGH);
  digitalWrite(amberBank2, HIGH);
 
  digitalWrite(redBank2a, HIGH);
  digitalWrite(amberBank2a, HIGH);
  delay(shortDelay);  
}

void red2(){
  digitalWrite(redBank1,HIGH);                    
  
  digitalWrite(redBank1a,HIGH);
  
  digitalWrite(redBank2, LOW);
  digitalWrite(amberBank2, LOW);
  digitalWrite(greenBank2, HIGH);
  
  digitalWrite(redBank2a, LOW);
  digitalWrite(amberBank2a, LOW);
  digitalWrite(greenBank2a, HIGH);
  delay(mediumDelay);
}

void red3(){
  digitalWrite(redBank1, HIGH);              
  
  digitalWrite(redBank1a, HIGH);  
  digitalWrite(greenBank2, LOW);
  digitalWrite(amberBank2, HIGH);
  
  digitalWrite(greenBank2a, LOW);
  digitalWrite(amberBank2a, HIGH);
  delay(shortDelay);
}

void red4(){
  digitalWrite(redBank1, HIGH);
  digitalWrite(amberBank1, HIGH);
  
  digitalWrite(redBank1a, HIGH);
  digitalWrite(amberBank1a, HIGH);
  
  digitalWrite(amberBank2, LOW);
  digitalWrite(redBank2, HIGH);
  
  digitalWrite(amberBank2a, LOW);
  digitalWrite(redBank2a, HIGH);
  delay(shortDelay);
}

void green1(){
  digitalWrite(redBank1, LOW);
  digitalWrite(amberBank1, LOW);
  digitalWrite(greenBank1, HIGH);
  
  digitalWrite(redBank1a, LOW);
  digitalWrite(amberBank1a, LOW);
  digitalWrite(greenBank1a, HIGH);
  
  digitalWrite(redBank2, HIGH);
  
  digitalWrite(redBank2a, HIGH);
  delay(longDelay);
}

void amber1(){
  digitalWrite(greenBank1, LOW);
  digitalWrite(amberBank1, HIGH);
  
  digitalWrite(greenBank1a, LOW);
  digitalWrite(amberBank1a, HIGH);
  
  digitalWrite(redBank2 , HIGH);
  
  digitalWrite(redBank2a , HIGH);
  delay(shortDelay);
}

/*
 * The main loop calls each function1 line at a time it then goes to the function called and works through it one
 * line until it reaches the end of that function. it then returns to the next line in the void loop.
 * Once it completes the last line in the void loop it will return to the first line of the loop.
 */
void loop() {
  red1();
  red2();
  red3();
  red4();
  green1();
  amber1();
 

}
