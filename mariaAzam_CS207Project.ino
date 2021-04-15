/*
  Interactive Gesture-Controlled Table Lamp

  This sketch will configure an LED to turn on and change colours
  when 5 IR sensors are activated from one end to the other.

  by Maria Azam
  29 Mar 2021
  Adapted from 'Random Stuff We Make's' code found at: 
    https://www.hackster.io/rswm/gesture-controlled-interactive-table-light-3f8bd7#code
*/

// Arrays to store the properties of each of the 5 IR sensors
const int NUM_SENSORS = 5;
int IRSensorState[NUM_SENSORS] = {0, 0, 0, 0, 0};          // The state (HIGH || LOW) of each IR sensor
const int IRSensorPins[NUM_SENSORS] = {3, 4, 5, 6, 7};     // The data pin of each IR sensor

// Variables to store the properties of the LED
int ledState = 0;                                // The state (HIGH || LOW) of the LED
const int ledPinRed = 9;                         // The data pin for the red pin of the LED
const int ledPinGreen = 10;                      // The data pin for the green pin of the LED
const int ledPinBlue = 11;                       // The data pin for the blue pin of the LED

int swipeDetected = 0;        // Stores the number of swipes on the IR Sensors

void setup() 
{
  // Set all 5 IR sensor pins as inputs
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    pinMode(IRSensorPins[i], INPUT);
  }

  // Set all RGB LED pins as outputs
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
}

void loop() 
{
  // Read input from all sensors
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    digitalRead(IRSensorPins[i], IRSensorStates[i]);
  }

  // Check whether or not all sensors have been activated
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    // If any sensor has not been activated, a swipe was not detected, so exit the loop
    if (IRSensorStates[i] == LOW)
    {
      swipeDetected = false;
      break;
    }

    // Otherwise, all sensors were activated, so a swipe was detected
    swipeDetected = true;
  }

  // If a swipe was detected, turn on the LED to red
  if (swipeDetected)
  {
      analogWrite(ledPinRed, 255);
      analogWrite(ledPinGreen, 0);
      analogWrite(ledPinBlue, 0);
  }
  // Otherwise, turn off the LED
  else
  {
      analogWrite(ledPinRed, 0);
      analogWrite(ledPinGreen, 0);
      analogWrite(ledPinBlue, 0);
  }

  // Allow light to stay on for 10 ms before checking for new swipes
  delay(10);
}
