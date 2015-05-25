int newState = HIGH, oldState = HIGH, ledState = LOW;
void setup()  // Initialization, only runs once
{
	pinMode(3, OUTPUT);  // Set pin 3 as output
	pinMode(2, INPUT);   // Set pin 2 as input
}
void loop()  // Looping section runs after setup()
{
	newState = digitalRead(2);  // Assign the digital status (HIGH/LOW) to newStates

	if ((oldState == HIGH)&&(newState==LOW))  // If the oldState is HIGH and newState is LOW
	{

		delay(20);  // Delay 20 ms.

		if(ledState==HIGH)  // If the LED is on
		{
			digitalWrite(3, LOW);  // Turn to off
			ledState=LOW;          // Change the status to off too
		}
		else
		{
			digitalWrite(3, HIGH); // Turn to on
			ledState=HIGH;         // Change the status to on too
		}
	}

	oldState=newState;  // Swap the oldState to current newState
} 
