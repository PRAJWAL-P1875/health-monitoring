
💓 Health Monitoring System using Arduino
This project is a real-time health monitoring system that measures pulse rate (BPM), body temperature, humidity, and tracks location (GPS). The collected data is transmitted wirelessly to a mobile device via Bluetooth (HC-05), making it ideal for remote health tracking.

🛠️ Components Used
Component	Quantity	Description
Arduino Uno/Nano/Mega	1	Microcontroller Board
Pulse Sensor	1	Analog heart rate monitor (connected to A0)
DHT11 Sensor	1	For temperature and humidity monitoring (D2)
GPS Module (e.g., NEO-6M)	1	For location tracking (TX to D10, RX to D11)
Bluetooth Module (HC-05)	1	For wireless communication (TX to D6, RX to D5)
Jumper Wires	Several	For connections
Voltage Divider	2 sets	For safe voltage levels to HC-05 & GPS RX pins

⚙️ Pin Connections
Module	Arduino Pin
DHT11	D2
Pulse Sensor	A0
HC-05 TX	D6
HC-05 RX	D5 (via voltage divider)
GPS TX	D10
GPS RX	D11 (via voltage divider)

🧠 How It Works
Pulse Monitoring: The analog signal from the pulse sensor is read and mapped to a BPM value.

Temperature & Humidity: DHT11 sensor provides temperature and humidity readings.

GPS Tracking: The GPS module fetches the location coordinates.

Bluetooth Output: All sensor data is sent over Bluetooth to a connected mobile device.

Serial Monitor: Data is also printed to the Serial Monitor for debugging or real-time view.

🖥️ Sample Output
yaml
Copy
Edit
BPM: 74 | Temp: 27.50°C | Hum: 48.00% | GPS: $GPGGA,134522.00,1325.2210,N,07708.5100,E,1,08,1.01,897.0,M,-34.0,M,,*68
gps-13°25'22 ,77°8'51
⌛ Delay
A 2-second delay is included between each loop iteration to allow sensors to stabilize and prevent flooding of the serial output.

📱 Mobile Integration
Use any Bluetooth terminal app (like Serial Bluetooth Terminal on Android) to receive and view health and GPS data.

The project can be integrated with health monitoring mobile apps for real-time alerts.

📦 Future Scope
Add fall detection using accelerometers

Store data on SD card or cloud (IoT)

Add alert system (SMS or buzzer) for abnormal health readings

Expand with oxygen level sensors (SpO2)

📸 Screenshots
![WhatsApp Image 2025-07-22 at 11 07 47_f6e9d82c](https://github.com/user-attachments/assets/7d16c53f-0b10-4daa-8a1f-d4e12c5a5c4d)


🔖 Tags
Arduino Health Monitoring Pulse Sensor DHT11 Bluetooth GPS Wearable Health Remote Health Tracker
