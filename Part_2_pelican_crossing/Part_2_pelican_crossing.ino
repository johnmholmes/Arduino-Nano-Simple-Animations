/* Disclaimer
 * This code is written for an Arduino Nano and has been tested on am Arduino Nano clone.
 * The code may work on other boards but has not been tested on them.
 *  
 * The Nano will sit on a sensor shield which makes it easier to access the Input / outputs. 
 * And supply the power required for the project.
 * 
 * I use pre soldered LEDS with Resistors already fitted. The will be connected to pins 3 to pin 12 for this sketch.
 * 
 * And a swicth will be connected to pin A1
 * 
 * The project is to demonstrate simple model railway animations in this case a uk Pelican crossing.
 * The times can be adjusted to waht ever you want in the ***Delay setting
 * 
 * 
 */

 /* First we will declare to constant variables for the LED's and then for the push button
 * This will assist in easier reading of the sketch.
 * In this sketch it is not really required but its good to get use to working in this way. As codes get 
 * more complexed it will pay divends for you.
 * 
 * Before people complain I am using delay in this sketch please understand there is no need for interupts.
 * So there is no problem doing so.
 */

 const int bank1Green = 3;
 const int bank1Amber = 4;                                 //Pin 4S on shield
 const int bank1Red = 5;                                   //Pin 5S on shield

 const int bank2Green = 6;                                 //Pin 6S on shield
 const int bank2Amber = 7;                                 //Pin 7S on shield
 const int bank2Red = 8;                                   //Pin 8S on shield

 const int walk1Safe = 9;                                  //Pin 9S on shield
 const int walk1Stop = 10;                                 //Pin 10S on shield

 const int walk2Safe = 11;                                 //Pin 11S on shield
 const int walk2Stop = 12;                                 //Pin 12S on shield

 const int pushButton = A1;                                //Pin A1S on the shield

 const int triggerDelay = 2000;                            //Time to wait before changing the lights 
 const int safeCrossing = 10000;                           //Time to cross
 const int finishCrossing = 400;                           //Flashing amber to finish crossing

 int buttonState;                                          //Used to store the pin state of the button

 /*
  * In the setup we setup all the 12 leds as outputs using their variable names.
  * And setup the button pin as an input using an internal pull up resistor. This holds the pin high until the button is grounded
  */
void setup(){
 
  pinMode(bank1Green, OUTPUT);
  pinMode(bank1Amber, OUTPUT);
  pinMode(bank1Red, OUTPUT);

  pinMode(bank2Green, OUTPUT);
  pinMode(bank2Amber, OUTPUT);
  pinMode(bank2Red, OUTPUT);

  pinMode(walk1Safe, OUTPUT);
  pinMode(walk1Stop, OUTPUT);

  pinMode(walk2Safe, OUTPUT);
  pinMode(walk2Stop, OUTPUT);

  pinMode(pushButton, INPUT_PULLUP);

  
  /*
   * I will not set the drivers green leds to on when the Arduino starts up.
   * And will set the pedestrians lights to red on start up.
   */
  digitalWrite(bank1Green, HIGH);
  digitalWrite(bank2Green, HIGH);
  digitalWrite(walk1Stop, HIGH);
  digitalWrite(walk2Stop, HIGH);

}

/*
 * For this sketch I am going to be using a total of 7 functions which will control the various stages of the program.
 * 
 * Once the if statement gets to be true IE the button has been pressed and making A1 go low
 * The first function gets called Amber()
 * The program will go one line at a time starting with setting bank1green off and the steps through each line.
 * 
 * until it gets to the final line in this case delay once the delay has been finished it returns back to the next line 
 * in the void loop().
 * 
 * As the functions are basically very similar I will not explain them
 */

 /*Amber function needs to turn off the green leds and turn on the amber leds
  *Then delay for 2 seconds before returning back to the main loop() function
 */
 void Amber(){
  digitalWrite(bank1Green, LOW);
  digitalWrite(bank2Green, LOW);
  digitalWrite(bank1Amber, HIGH);
  digitalWrite(bank2Amber, HIGH);
  delay(triggerDelay);
 }

  void RedSafe(){

  digitalWrite(bank1Amber, LOW);
  digitalWrite(bank2Amber, LOW);
  digitalWrite(bank1Red, HIGH);
  digitalWrite(bank2Red, HIGH);
  delay(triggerDelay);

  }

  void walk(){
  digitalWrite(walk1Stop, LOW);
  digitalWrite(walk2Stop, LOW);
  digitalWrite(walk1Safe, HIGH);
  digitalWrite(walk2Safe, HIGH);
  delay(safeCrossing);
  
 }

  void donotWalk(){
  digitalWrite(walk1Safe, LOW); 
  digitalWrite(walk2Safe, LOW);  
  digitalWrite(walk1Stop, HIGH);
  digitalWrite(walk2Stop, HIGH); 
  delay(triggerDelay);  
  }

  void Amber1(){
  digitalWrite(bank1Green, LOW);
  digitalWrite(bank2Green, LOW);
  digitalWrite(bank1Amber, HIGH);
  digitalWrite(bank2Amber, HIGH);
  digitalWrite(bank1Red, HIGH);
  digitalWrite(bank2Red, HIGH);
  delay(triggerDelay);
 }

 void Amber2(){
  digitalWrite(bank1Red, LOW);
  digitalWrite(bank2Red, LOW);
  delay(triggerDelay);
  digitalWrite(bank1Amber, HIGH);
  digitalWrite(bank2Amber, HIGH);
  delay(finishCrossing);
  digitalWrite(bank1Amber, LOW);
  digitalWrite(bank2Amber, LOW);
  delay(finishCrossing);
  digitalWrite(bank1Amber, HIGH);
  digitalWrite(bank2Amber, HIGH);
  delay(finishCrossing);
  digitalWrite(bank1Amber, LOW);
  digitalWrite(bank2Amber, LOW);
  delay(finishCrossing);
  digitalWrite(bank1Amber, HIGH);
  digitalWrite(bank2Amber, HIGH);
  delay(finishCrossing);
 }

 void Green(){
  digitalWrite(bank1Amber, LOW);
  digitalWrite(bank2Amber, LOW);
  digitalWrite(bank1Red, LOW);
  digitalWrite(bank2Red, LOW);
  digitalWrite(bank1Green, HIGH);
  digitalWrite(bank2Green, HIGH);
  }
 
 /*
  * The void loop() will run only when the if statement condition is meet.
  * I use a variable to record if the button is pressed each time it completes a full loop.
  * There is a delay after the button is pressed this could have been put in the Amber() function.
  * I just prefer to have with the if statement.
  */
 void loop() {
  buttonState = digitalRead(pushButton);
   
  if (buttonState == LOW){
    delay(triggerDelay);
    
    Amber();
    
    RedSafe();
    
    walk();
    
    donotWalk();
    
    Amber1();
    
    Amber2();
    
    Green();
    }
  
  }
