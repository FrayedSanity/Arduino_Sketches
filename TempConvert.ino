/*This application is intended to convert an integer temperature in degrees
Celcius to degrees Fahreheit.

// TBD -- Project
// 1. Ask user for temperature in C
// 2. Read user input from console (serial)
// 3. Ensure the value is numeric.
// 	3a. Go to 4. if numeric.
//	3b. Inform user that the value entered was not numeric, Go to step 1.
// 4. Preform conversion as shown in setup and ask user to enter a new temperature in C.
// 5. Go to step 2.

// see if you can do this above.  i will also do it and we can compair results and implementation.
// Accept Challenge 	[X]
// Decline Challenge	[ ]


Developer: Wes Urbat
Version 1.0-1
Last Modified: 03.28.16*/

//#include 

void setup()
{

	//This is my first attempt at discovering uses and playing more indepth with
	//serial communication functions.

	Serial.begin(9600); //Opens a serial connection at a baud rate of 9600 bps (bits per second)
	while (!Serial) {
		; //Wait for serial connection to open.
	}
	Serial.println();
	Serial.println();
	Serial.println("degC => degF    Temperature Conversion Tool      v.1.0-0");

	Serial.println();
	Serial.println();
	
	
	////This is my first very crude attempted at taking a serial input and repeating it back to the serial com window.
	int inputChar = 0;
	Serial.flush();
	Serial.println("Please enter a temperature in Celcius.");

	int timeDelay = 10000;
	long int startTime = millis();
	
	while (millis() < startTime + timeDelay) //determined I needed a delay to allow a serial input to be buffered
	{
		//Buffer serial input
	}

	int myBytes = Serial.available(); //Wanted to see how Serial.available worked.
	
	
	if (Serial.available() > 0)
	{
		
		inputChar = Serial.read();

		Serial.println();
		Serial.print("The value entered was:");
		Serial.println(inputChar);  //I found out this returns the ASCII value not the actual literal value.

		Serial.println();
		Serial.print("The first byte of data in binary is: ");
		Serial.println(inputChar, BIN);
	}
	else
	{
		Serial.println("No data in buffer.");
	}
}

void loop()
{
	/*float tempF; 	 //Declare local "loop" variable.
	tempF = CtoF();
	Serial.print("The Temperature in Fahreheit is ");
	Serial.print("tempF");*/
}

//function will eventually be used when I determine the best way to evaluate a serial stream and
//convert the value to a temperature in Fahreheit.  I think I might even make it two functions.
//1. Validate Float Input
//2. Convert valid input into Fahreheit temperature.
float CtoF()
{
	int inputChar;
	Serial.println("Please enter a temperature in Celcius.");
	if (Serial.available() > 0)
	{
		inputChar = Serial.read();
		Serial.print("The first byte of data is: ");
		Serial.println(inputChar, BIN);


		//int degF = ((degC * 9) / 5) + 32; // Declare local "setup" variable "degF" and assign value based on C to F conversion.
		//Serial.println(degF); //print the result via serial (USB) to output window on PC.
	}
}
