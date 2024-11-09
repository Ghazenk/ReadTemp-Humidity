#include <DHT.h>

#define DHTPIN 13      // Pin where the DHT11 data pin is connected
#define DHTTYPE DHT11  // Define the sensor type (DHT11)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
}

void loop() {
    delay(2000);  // Delay between readings

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
    } else {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C   Humidity: ");
        Serial.print(humidity);
        Serial.println("g.m^-3 ");
    }
}
