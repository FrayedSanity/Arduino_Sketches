/*BlinkWithoutDelay
This sketch will extend the concept of the Blink sketch but now allow
the PIN 13 LED to blink without delay other logic running the the "Loop"
functioin.

Developer: Wes Urbat
Last Modified:  03.12.16 @ 22:30
*/

//Note no additional libraries were loaded using the #include preprocessor directive.

//Variable declarations

//Constant this value will not change
const int LED_Pin = 13;			//PIN number of the only built-in actuator on the board.
const long BlinkFreq = 1000;	//LED blink frequency in milliseconds.

//Standard variable whos value will change
int LED_State = LOW;			//Initial LED state - De-energized

//Time variable in milliseconds generally use an "unsigned long" if value is expected to be large.
unsigned long PreviousTime = 0;	//Initialize value at 0ms, will store last millis() value.

//The setup function runs only once during reset of the microcontroller or when power is initially supplied.
void setup()
{
	//Setup Digital Output pins
	pinMode(LED_Pin, OUTPUT);		//Initialize the PIN 13 Mode

	//Setup Digital Input pins

}

// The loop function runs continuously at the update rate of the microcontroller.
void loop()
{
	//Determine if the LED is suppose to be ON or OFF. First scan LED will be OFF.
	//Using the "millis()" function current time will be compare to the previous scan time.
	//This method allow the "loop" function to perform other actions while blinking the LED.
	
	unsigned long CurrentTime = millis();
	if (CurrentTime - PreviousTime >= BlinkFreq)
	{
		//Update PreviousTime to CurrentTime
		PreviousTime = CurrentTime;

		//change the state of the LED to the opposite state
		if (LED_State == LOW)
		{
			LED_State = HIGH;
		}
		else
		{
			LED_State = LOW;
		}
		digitalWrite(LED_Pin, LED_State); //Turns the output for LED_Pin ON or OFF (HIGH/LOW).
	}
	//Other code needing to excute each scan while LED blinks goes here.
}
