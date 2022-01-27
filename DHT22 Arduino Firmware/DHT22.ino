// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

byte incomingByte = 0;   // for incoming serial data
float h = 0, t = 0;
#define WRITE_COM 0x31

void setup() {
  Serial.begin(115200);
  Serial.println("DHT22 Start");
  dht.begin();
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    if (incomingByte == WRITE_COM){
      // Reading temperature or humidity takes about 250 milliseconds!
      // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
      h = dht.readHumidity();
      // Read temperature as Celsius (the default)
      t = dht.readTemperature();
      // Read temperature as Fahrenheit (isFahrenheit = true)
      //  float f = dht.readTemperature(true);

      // Check if any reads failed and exit early (to try again).
      if (isnan(h) || isnan(t)/* || isnan(f)*/) {
        Serial.println("Failed to read from DHT sensor!");
        return;
       }
  
//      Serial.print(t);
//      Serial.print("\t");
//      Serial.println(h);
        Serial.println(String(t)+"\t"+String(h)); 
        delay(100);
    }
  }
  // to keep values up to date
  h = dht.readHumidity();
  t = dht.readTemperature();
}
