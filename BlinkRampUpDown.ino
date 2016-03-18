/*This program is an introduction to the "if" statement.  In this program
The onboard PIN 13 LED Will start flashing at a starting frequency and ramp
down to a threshold frequency and then ramp up to a threshold frequency.
This oscillation will be continuous.

Developer: Wes Urbat
Last Modified: 03.17.16*/


//Initial global variable declaration and assignment
int freq = 1000; //defines the frequency that the LED will be flashed.
int freqRamp = 100; //defines the frequency ramp rate +/- per scan.
int freqMin = 0; //defines the minimum frequency in ms.
int freqMax = 2000; //defines the maximum frequency in ms.
int Pin = 13; //defines the pin the LED will be connected to
bool minReached = false; //trigger for min freq reached.

void setup()
{
	
	//Initialize and configure hardware
	Serial.begin(9600); //This opens the serial commuincation at a baud rate of 9600bps bits per second.
	pinMode(Pin, OUTPUT); //defines the specified PIN as an output
	
}

void loop()
{
	//One period is defined as the LED going from HIGH to LOW back to High.	
	digitalWrite(Pin, HIGH);
	delay(freq);
	digitalWrite(Pin, LOW);
	delay(freq);

	//Determines if the current frequency is less or equal to Minimum frequency
	//or greater than or equal to the maximum frequency, and in return causing the
	//frequency of the LED flash to ramp up or down.
	if (!minReached)
	{
		freq = freq - freqRamp;
		Serial.println(freq); //Outputs current frequency in ms to the USB to the PC's monitor.

		if (freq <= freqMin)
		{
			minReached = true;
		}
		else{}
	}
	else
	{
		freq = freq + freqRamp;
		Serial.println(freq); //Outputs current frequency in ms to the USB to the PC's monitor.
		if (freq >= freqMax)
		{
			minReached = false;
		}
	}
}
