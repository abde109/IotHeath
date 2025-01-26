# IoT Remote Health Monitoring System

This project is part of the "Master Informatique Appliquée Offshoring" program and focuses on the development of an IoT-based remote health monitoring system.

---

## Project Description

The system enables the remote monitoring of vital health parameters such as:
- Body temperature
- Heart rate
- Blood oxygen saturation (SpO2)

### Features
- Real-time data collection and visualization.
- Anomaly detection with immediate notifications.
- Web interface for intuitive data tracking.

---

## Tools and Technologies

1. **Arduino UNO Library for Proteus**
   - Simulation of microcontrollers and sensors like Heart Beat Sensor, LM35, etc.
2. **com0com**
   - Virtual serial port communication setup.
3. **Windows Sandbox**
   - Isolated environment for safe testing.
4. **Mosquitto MQTT**
   - Lightweight protocol for real-time data transmission.
5. **Flask**
   - Python micro-framework for web development.
6. **Bootstrap**
   - Frontend framework for responsive design.
7. **Visual Studio Code (VSCode)**
   - Code editor for development.
8. **Arduino IDE**
   - Programming and testing microcontrollers.
9. **Python 3.13.1**
   - Backend and business logic implementation.

---

## Installation Instructions

### Prerequisites
- Install [Arduino IDE](https://www.arduino.cc/en/software)
- Install [Python 3.13.1](https://www.python.org/downloads/)
- Install [Mosquitto MQTT Broker](https://mosquitto.org/download/)
- Install and configure [com0com](http://com0com.sourceforge.net/)

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/abde109/IotHeath.git
   ```
2. Navigate to the project directory:
   ```bash
   cd IoHealth
   ```
3. Install Python dependencies:
   ```bash
   pip install -r requirements.txt
   ```
4. Configure virtual ports using **com0com**.
5. Run the Flask server:
   ```bash
   python main.py
   ```
6. Start the serial-to-MQTT bridge:
   ```bash
   python serial_to_mqtt.py
   ```
7. Launch the Proteus simulation to visualize sensor data.

---

## How to Use

1. Open the Proteus project file and start the simulation.
2. Open the web interface by navigating to:
   ```
   http://localhost:5000
   ```
3. View real-time health data and receive alerts for anomalies.

---

## Project Status
- Real-time data monitoring and notification system: **Completed**
- Database integration for anomaly storage: **Pending**
- User management and patient profiles: **Pending**

---

## License
This project is open-source and available under the MIT License.

---

## Contact
For questions or contributions, contact:
- **Author:** Khadri abderrahim
- **Supervisor:** Mme Hafssa BENABOUD
- **Repository:** https://github.com/abde109/IotHeath.git
