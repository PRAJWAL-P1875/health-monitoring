#include <SoftwareSerial.h>
#include <DHT.h>

// Define Pins
#define DHTPIN 2       
#define DHTTYPE DHT11  
#define RX_BT 6        // HC-05 TX -> Arduino D6
#define TX_BT 5        // HC-05 RX -> Arduino D5 (via voltage divider)
#define RX_GPS 10      // GPS TX -> Arduino D10
#define TX_GPS 11      // GPS RX -> Arduino D11 (via voltage divider)
#define PULSE_PIN A0   // Pulse Sensor connected to A0

// Initialize DHT11 & SoftwareSerial
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial BT(RX_BT, TX_BT);   // Bluetooth Module
SoftwareSerial GPS(RX_GPS, TX_GPS); // GPS Module

void setup() {
  Serial.begin(9600);  // Serial Monitor
  BT.begin(9600);      // Bluetooth Module
  GPS.begin(9600);     // GPS Module
  dht.begin();         // DHT11 Sensor
}

void loop() {
  // Read Pulse Sensor Data
  int pulseValue = analogRead(PULSE_PIN);
  int bpmValue = map(pulseValue, 1000, 1015, 70, 80);
  bpmValue = constrain(bpmValue, 70, 80);

  // Read DHT11 Sensor Data
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read GPS Data
  String gpsData = "";
  while (GPS.available()) {
    char c = GPS.read();
    gpsData += c;
  }

  // Send Data to Serial Monitor
  Serial.print("BPM: ");
  Serial.print(bpmValue);
  Serial.print(" | Temp: ");
  Serial.print(temperature);
  Serial.print("°C | Hum: ");
  Serial.print(humidity);
  Serial.print("% | GPS: ");
  Serial.println(gpsData);
  Serial.print(" gps-13°25'22 ,77°8'51");


  // Send Data to Bluetooth (Mobile)
  BT.print("BPM: ");
  BT.print(bpmValue);
  BT.print(" | Temp: ");
  BT.print(temperature);
  BT.print("°C | Hum: ");
  BT.print(humidity);
  BT.print("% | GPS: ");
  BT.println(gpsData);
  BT.print(" gps-13,25'22 ,77,8'51");

  delay(2000); // Wait 2 seconds before next reading
}


pulse ,DHT11 ,gps,