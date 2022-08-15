#include <Arduino.h>
#include "sim.h"
#include "light_detection.h"

#define LIGHT_SENSOR_PIN_LT 9  // left top
#define LIGHT_SENSOR_PIN_RT 10 // right top
#define LIGHT_SENSOR_PIN_RB 11 // right bottom
#define LIGHT_SENSOR_PIN_LB 12 // left bottom

LightDetector lightDetector(LIGHT_SENSOR_PIN_LT, LIGHT_SENSOR_PIN_RT, LIGHT_SENSOR_PIN_RB, LIGHT_SENSOR_PIN_LB);

void setup()
{
  Serial.begin(9600);
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pingSim();
}

void loop()
{
  LightDetectionResult lightDetectionResult = lightDetector.measure();
  LightDetectionMovementResult movementPlot = lightDetector.plotMovement(lightDetectionResult);
}