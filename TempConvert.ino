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
  
  // TBD -- Project
  // 1. Ask user for temperature in C 
  // 2. Read user input from console (serial)
  // 3. Ensure the value is numeric.
  // 	3a. Go to 4. if numeric.
  //	3b. Inform user that the value entered was not numeric, Go to step 1.
  // 4. Preform conversion as shown in setup and ask user to enter a new temperature in C.
  // 5. Go to step 2.
  
  // see if you can do this above.  i will also do it and we can compair results and implementation.
  // Accept Challenge 	[ ]
  // Decline Challenge	[ ]
 
}
