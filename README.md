🌟 SmartStreetLite – Intelligent Street Lighting System
🚦 Overview
SmartStreetLite is a smart street lighting system built using Arduino that automatically controls street lights based on environmental conditions and motion detection. The project aims to save energy by turning lights ON only when necessary, enhancing both efficiency and safety.

🧠 Features
🌗 Ambient Light Detection using LDR sensor to detect day/night.

🕴️ Motion Detection using Ultrasonic Sensor to turn on lights only when people or vehicles are nearby.

📡 Obstacle Sensing using IR Sensor for close-range detection.

⚡ Energy-efficient: Lights remain OFF during daylight and idle times.

🔄 Fully automated logic with real-time sensing.

🔧 Components Used
1 × Arduino UNO

1 × LDR Sensor (Light-dependent resistor)

1 × Ultrasonic Sensor (HC-SR04)

1 × IR Sensor

1 × Relay Module / LED (for simulating the streetlight)

Jumper wires and breadboard

Power supply (USB or battery)

🧰 How It Works
During daylight, lights remain OFF based on the LDR reading.

During night, the light turns ON only if:

Ultrasonic sensor detects motion (vehicle/human)

or IR sensor detects a nearby object

Light remains ON for a few seconds, then automatically turns OFF if no further motion is detected.

💡 Circuit Logic
LDR → Reads light intensity (sets day/night mode)

Ultrasonic → Detects motion (> 30cm range)

IR Sensor → Detects close proximity

Arduino processes inputs and controls output (light)

🧪 Sample Code Snippet
if (ldrValue < threshold) { // Night
  if (ultrasonicDetectsMotion() || irSensorTriggered()) {
    digitalWrite(lightPin, HIGH);
  } else {
    digitalWrite(lightPin, LOW);
  }
} else {
  digitalWrite(lightPin, LOW); // Daytime
}
📦 Future Improvements
Solar-powered version for sustainability

Integration with IoT platforms (e.g., Blynk, ThingSpeak)

GSM module for remote control and monitoring

📸 Screenshots / Circuit Diagram
![image](https://github.com/user-attachments/assets/54c3028f-ad4c-47cc-9522-50a42d6d0dba)

👨‍💻 Author
Sujoy Sen
B.Tech CSE, PES University
