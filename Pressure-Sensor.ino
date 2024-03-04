#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_CS D0 // Chip select pin for BMP280
#define BMP_SCK D8 // SCK pin
#define BMP_MISO D9 // MISO pin
#define BMP_MOSI D10 // MOSI pin

// Initialize Adafruit BMP280 using SPI
Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);

void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  // Set up oversampling and filter initialization
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     // Operating Mode.
                  Adafruit_BMP280::SAMPLING_X2,     // Temp. oversampling
                  Adafruit_BMP280::SAMPLING_X16,    // Pressure oversampling
                  Adafruit_BMP280::FILTER_X4,      // Filtering.
                  Adafruit_BMP280::STANDBY_MS_500); // Standby time.
}

void loop() {
  float pressurePa = bmp.readPressure(); // Read pressure in Pascals
  //float pressurePsi = pressurePa / 6894.76; // Convert to psi
  Serial.print(F("Pressure = "));
  Serial.print(pressurePa);
  Serial.println(" Pa");

  delay(1000); // Wait for a second
}