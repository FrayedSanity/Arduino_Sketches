/*Blink
This sketch manipulates the only built-in actuator on the Arduino board.
"PIN 13 LED". 

More specifically this sketch will continuously flash the PIN 13 LED at
a 1hz cycle.

Developer: Wes Urbat
Modified Date: 03.12.16
*/




//The setup function runs once when reset is pressed or the board is first powered.
void setup()
{
	//Initialize Digital Pin 13 as an output.
	pinMode(13, OUTPUT);
}

/* The loop function runs continuously at the prefefined update rate of the
micro controller.*/
void loop()
{
	digitalWrite(13, HIGH);		//Turns the LED on PIN 13 on (HIGH is the voltage level 5V?)
	delay(1000);				//The routine holds for 1000ms or 1s before executing the next line of code.
	digitalWrite(13, LOW);		//Turns the LED on PIN 13 off (LOW is the removal of voltage 0V?)
	delay(1000);				//The routine holds for another 1000ms or 1s before executing the first line of code in "Loop" again.
  /* add main program code here */
}
