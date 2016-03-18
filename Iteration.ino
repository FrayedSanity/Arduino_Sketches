/*This program explores several different C commands used to peform a
finite interative task.  The following C commands will be used:
- if
- for
- while

The task will be simply flashing the built-in PIN 13 LED a finite number
of times.

Developer: Wes Urbat
Modified Date: 03.18.16*/


//Declare and assign intial values to global variables
int pin = 13; //Pin 13 is assoicated with the built-in LED.
int freq = 500; //defines the LED flash frequency
int i = 0; //iteration variable
int itrMax = 5; //Max interations
int LEDstate = LOW; //initial LED state on or off (HIGH/LOW)
int oneCycle = 0; //Detects whethere LED has executed one cycle (On to Off to On)
unsigned long previousTime = 0; //used to capture the previous scans time in ms.
unsigned long currentTime = millis(); //initialize current time
bool firstPrint = true; //detects whether to print a serial output for the first time.
bool meth1Comp = false; //method 1 completion flag
bool meth2Comp = false; //method 2 completion flag

//logic to detect first loop scan
//bool firstScanAfterLoopStart = true; //Used to detect first "loop" scan

void setup()
{

	/* Initialize hardware */
	pinMode(pin, OUTPUT); //Defines the specified PIN as an OUTPUT.
	Serial.begin(9600); //Opens the serial commuincation at a baud rate of 9600bps bits per second.

}

void loop()
{

	//Peform the finite interative task of flashing the LED with 3
	//separate methods.
	
	//Why can't a variable declaration be performed using a single scan if statment?
	//This forces the declaration to be global.
	//The logic commented out below violates complier rules.
	/*if (firstScanAfterLoopStart)
	{
		int freq = 1000; //defines the LED flash frequency
		int i = 0; //iteration variable
		int itrMax = 5; //Max interations
		int LEDstate = LOW; //initial LED state on or off (HIGH/LOW)
		unsigned long previousTime = 0; //used to capture the previous scans time in ms.
		unsigned long currentTime = millis(); //initialize current time
		firstScanAfterLoopStart = false;
		bool meth1Comp = false;
		bool meth2Comp = false;
	}*/

	currentTime = millis(); //Note this line of code is not executed when for or while loops are running.
	
	//Note these is a possibility there is reusable code in each method that would
	//be better served as a function.

	//METHOD 1 "if"
	
	if (!meth1Comp)
	{
		if (firstPrint)
		{
			Serial.println("Method 1 \"if\" begins...");
			firstPrint = false;
		}
		if (i < itrMax && currentTime >= previousTime + freq)
		{
			if (LEDstate == LOW)
			{
				LEDstate = HIGH;
			}
			else
			{
				LEDstate = LOW;
			}
			digitalWrite(pin, LEDstate);
			previousTime = currentTime;
			oneCycle++;
			if (oneCycle >= 2)
			{
				i++;
				Serial.println(i);
				oneCycle = 0;
			}
			if (i >= itrMax)
			{
				meth1Comp = true;
				firstPrint = true;
				i = 0; //initialize for next method's for loop.
			}
		}
	}
	

	//Method 2 "for"

	/*The for command is typically composed of three expressions.
	1 - iteration variable initialization
	2 - iteration variable comparision, used to end for loop.
	3 - iteration variable incriment / decriment expression.
	for(init;compare;inc.dec){}*/

	if (meth1Comp && currentTime >= previousTime + 5*freq)
	{
		if (!meth2Comp)
		{
			if (firstPrint)
			{
				Serial.println("Method 2 \"for\" begins..."); //note the use of string "" and " within the string using a \ character.
				firstPrint = false;
			}
			for (;i < itrMax;) //Notice only comparision expression present.
			{
				for (oneCycle = 0; oneCycle < 2;)
				{
					currentTime = millis();
					if (currentTime >= previousTime + freq)
					{
						if (LEDstate == LOW)
						{
							LEDstate = HIGH;
						}
						else
						{
							LEDstate = LOW;
						}
						digitalWrite(pin, LEDstate);
						previousTime = currentTime;
						oneCycle++;
					}
				}
				i++;
				Serial.println(i);
			}
			meth2Comp = true;
			firstPrint = true;
			i = 0;
			oneCycle = 0;
		}
	}
	

	//Method 3 "while"
	if (meth2Comp && currentTime >= previousTime + freq * 5)
	{
		if (firstPrint)
		{
			Serial.println("Method 3 \"while\" begins..."); //note the use of string "" and " within the string using a \ character.
			firstPrint = false;
		} 
		while (i < 5)
		{
			while(oneCycle < 2)
			{
				currentTime = millis();
				if (currentTime >= previousTime + freq)
				{
					if (LEDstate == LOW)
					{
						LEDstate = HIGH;
					}
					else
					{
						LEDstate = LOW;
					}
					digitalWrite(pin, LEDstate);
					previousTime = currentTime;
					oneCycle++;
				}
			}
			i++;
			Serial.println(i);
			oneCycle = 0;
		}
	}
}
	