#include <Arduino.h>
// #include <DigiKeyboard.h>
#include <Keyboard.h>

unsigned long startTime = 0;
const unsigned long debounceTime = 30;

#define INPUT_PIN A0
#define PRESS_VALUE 50

void setup() {
	// pinMode(INPUT_PIN, INPUT_PULLUP);
	Serial.begin(115200);
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, HIGH);
	delay(1000);
	digitalWrite(LED_BUILTIN, LOW);
	Keyboard.begin();


}

void loop() {
	if (analogRead(INPUT_PIN) <= PRESS_VALUE && startTime != 0 && millis() - startTime >= debounceTime) {
		// DigiKeyboard.sendKeyStroke(0, (byte) KEY_ENTER);
		Keyboard.print("[");
		startTime = 0;
		Serial.println("Sent!");
		delay(1000);
	} else if (analogRead(INPUT_PIN) <= PRESS_VALUE && startTime == 0) {
		startTime = millis();
		Serial.println("Pressed!");
	}
}
