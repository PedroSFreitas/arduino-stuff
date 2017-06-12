#include <stdint.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define RED_PIN 6u
#define GREEN_PIN 9u
#define BLUE_PIN 10u

#define MAX_DELAY 250u

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void set_color(uint8_t red,uint8_t green, uint8_t blue) {
    analogWrite(RED_PIN, 255 - red);
    analogWrite(GREEN_PIN, 255 - green);
    analogWrite(BLUE_PIN, 255 - blue);
}

void setup() {
    Serial.begin(9600);
    Serial.println("Starting Arduino and flashing LEDS...\n");
    
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    set_color(255, 0, 0);
    delay(MAX_DELAY);
    set_color(0, 255, 0);
    delay(MAX_DELAY);
    set_color(0, 0, 255);
    delay(MAX_DELAY);

    sensors.begin();
}

void loop() {
    float temperature;
    
    sensors.requestTemperatures();
    temperature = sensors.getTempCByIndex(0);
    if (temperature <= 22) {
        Serial.print("It's cold in here: ");
        Serial.println(temperature);
        set_color(0, 0, 255);
    } else if (temperature <= 29) {
        Serial.print("It's quite normal in here: ");
        Serial.println(temperature);
        set_color(0, 255, 0);
    } else {
        Serial.print("Something is terrible wrong in here: ");
        Serial.println(temperature);
        set_color(255, 0, 0);
    }
    
    delay(MAX_DELAY + MAX_DELAY);
}

