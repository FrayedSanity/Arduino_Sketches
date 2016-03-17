/*The purpose of this program is to explore the basic serial interface
commands.  Serial.begin and Serialprintln

Developer: Wes Urbat
Last Modified: 03.16.16*/


void setup()
{

	Serial.begin(9600); //Opens the serial connection at a baud rate of 9600 bps (bits per second)
	int a = 2; //declare and assign "setup" local variable "a"
	int b = 2; //declare and assign "setup" local variable "b"
	int c = a + b; //declare "setup" local variable "c" and assign the value of "a" plus "b"
	Serial.println(c);

}

void loop()
{

  /* Empty, no continous code. */

}
