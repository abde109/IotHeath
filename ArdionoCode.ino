#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

// Pin configurations
const int HEART_RATE_SENSOR_PIN = A0; // Pin for heart rate sensor
const int TEMP_SENSOR_PIN = A1;       // Pin for temperature sensor
const int STATUS_LED_PIN = 13;       // Built-in LED for status indication

// Threshold configuration
const int HEART_RATE_THRESHOLD = 550;

// Object for handling the pulse sensor
PulseSensorPlayground heartRateSensor;

void initializeSensors() {
    heartRateSensor.analogInput(HEART_RATE_SENSOR_PIN);
    heartRateSensor.blinkOnPulse(STATUS_LED_PIN);
    heartRateSensor.setThreshold(HEART_RATE_THRESHOLD);

    if (heartRateSensor.begin()) {
        Serial.println("Capteur initialisé !");
    } else {
        Serial.println("Échec de l'initialisation du capteur.");
    }
}

float getTemperatureCelsius() {
    int rawTempValue = analogRead(TEMP_SENSOR_PIN);
    float voltage = rawTempValue * (5.0 / 1024.0); // Convert analog value to voltage
    return voltage * 100.0;                        // Convert voltage to Celsius (LM35)
}

float calculateOxygenSaturation(float bpm) {
    // Simulated SpO2 calculation based on BPM range
    if (bpm < 55) {
        return 90.0 + random(-2, 3); // Lower SpO2 for very low BPM
    } else if (bpm > 115) {
        return 92.0 + random(-3, 2); // Slightly reduced SpO2 for high BPM
    } else {
        return 95.0 + random(-1, 5); // Normal SpO2 range
    }
}

void setup() {
    Serial.begin(115200); // Initialize serial communication

    // Initialize sensors
    initializeSensors();
    pinMode(STATUS_LED_PIN, OUTPUT); // Configure LED pin
}

void loop() {
    // Read temperature data
    float temperatureC = getTemperatureCelsius();

    // Read heart rate data
    int currentBPM = heartRateSensor.getBeatsPerMinute();

    // Detect heartbeats
    if (heartRateSensor.sawStartOfBeat()) {
        Serial.println("♥ Battement détecté !");
    }

    // Calculate SpO2
    float simulatedSpO2 = calculateOxygenSaturation(currentBPM);

    // Maintain same output format for compatibility
    Serial.print("Temperature : ");
    Serial.print(temperatureC);
    Serial.println(" °C");

    Serial.print("BPM : ");
    Serial.println(currentBPM);

    Serial.print("SpO2 : ");
    Serial.print(simulatedSpO2);
    Serial.println(" %");

    delay(1000); // Refresh interval
}
