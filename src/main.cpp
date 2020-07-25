#include <Arduino.h>
#include <Keyboard.h>

unsigned long startTime = 0;
const unsigned long debounceTime = 30;

#define INPUT_PIN A0
#define PRESS_VALUE 10

void setup() {
	Serial.begin(115200);
	Keyboard.begin();


}

void loop() {
	// Serial.print("Analog: ");
	// Serial.println(analogRead(INPUT_PIN));

	if (analogRead(INPUT_PIN) <= PRESS_VALUE && startTime != 0 && millis() - startTime >= debounceTime) {
		Keyboard.print("[");
		startTime = 0;
		Serial.println("Sent!");
		delay(1000);
	} else if (analogRead(INPUT_PIN) <= PRESS_VALUE && startTime == 0) {
		startTime = millis();
		Serial.println("Pressed!");
	}
}
