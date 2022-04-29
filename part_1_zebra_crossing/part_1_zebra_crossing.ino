/* Disclaimer
 * This code is written for an Arduino Nano and has been tested on am Arduino Nano clone.
 * The code may work on other boards but has not been tested on them.
 *  
 * The Nano will sit on a sensor shield which makes it easier to access the Input / outputs. 
 * And supply the power required for the project.
 * 
 * I use pre soldered LEDS with Resistors already fitted. The will be connected to pins 3 and 4 for thsi sketch.
 * 
 * The project is to demonstrate simple model railway animations in this case a zebra crossing
 */

 /* First we will declare to constant variables for the LED's and the delay between blinking.
 * This will assist in easier reading of the sketch.
 * In this sketch it is not really required but its good to get use to working in this way. As codes get 
 * more complexed it will pay divends for you.
 * 
 * Before people complain I am using delay in this sketch please understand there is no need for interupts.
 * So there is no problem doing so.
 */

 const int led1 = 3;                  //Pin 3S on shield
 const int led2 = 4;                  //Pin 4S on shield

 const int flash = 500;               //500ms = 1/2 seconds

 // We now will setup the pins as outputs and set them to Off on bootup.

 void setup(){

  pinMode(led1, OUTPUT);              //Set led1 pin as an output
  pinMode(led2, OUTPUT);              //Set led2 pin as an output

  digitalWrite(led1, LOW);            //Set Led1 to off
  digitalWrite(led2, LOW);            //Set Led2 to off
 }
 

// Start of the main loop which runs for ever
 void loop(){
    digitalWrite(led1, HIGH);       //Led1 on
    digitalWrite(led2, LOW);        //Led2 off
    delay(flash);                   //delays for 1/2 second
    digitalWrite(led1, LOW);        //led1 off
    digitalWrite(led2, HIGH);       //led2 on
    delay(flash);                   //delays for 1/2 second then goes back to the start of the void loop.
  }                                 //end of the void loop
