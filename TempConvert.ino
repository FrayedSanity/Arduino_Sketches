/*This application is intended to convert an integer temperature in degrees
Celcius to degrees Fahreheit.

Developer: Wes Urbat
Last Modified: 03.16.16*/

void setup()
{

	Serial.begin(9600); //Opens a serial connection at a baud rate of 9600 bps (bits per second)
	int degC = 20; //Declare local "setup" variable and assign initial value.
	int degF = ((degC * 9) / 5) + 32; // Declare local "setup" variable "degF" and assign value based on C to F conversion.
	Serial.println(degF); //print the result via serial (USB) to output window on PC.

}

void loop()
{

  /* Empty, no continuous code. */

}
