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
  // Get digital input from all 5 IR Sensors
  readSensorStates();

  // Determine whether a swipe was detected & store the corresponding swipe number in 'swipeDetected'
  isSwipeDetected(swipeDetected);

  // Execute the specific task corresponding to the current swipe number
  taskOnSwipe(swipeDetected);

  // Wait before checking for new swipes
  delay(10);
}

// This function reads digital input from each of the IR Sensors
void readSensorStates()
{
  // Read input from all sensors
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    IRSensorState[i] = digitalRead(IRSensorPins[i]);
  }
}

// This function checks the state of all 5 IR Sensors to determine whether or not a swipe was detected
void isSwipeDetected(int & mySwipe)
{ 
  bool swipeDetected = true;
  
  // Check whether or not all sensors have been activated
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    // If any sensor has not been activated, a swipe was not detected
    if (IRSensorState[i] == HIGH)
    {
      swipeDetected = false;
    }
  }

  // If a swipe was decected, update the number of swipes stored in 'mySwipe'
  if (swipeDetected)
  {
    // Otherwise, all sensors were activated, so a swipe was detected
    mySwipe = (mySwipe + 1) % 8;
  }
}

// This function turns on the specific light colour corresponding to the number of swipes stored in 'mySwipe'
void taskOnSwipe(int mySwipe)
{
  switch (mySwipe)
  {
    case 1: // Red
      turnOnLights(255, 0, 0);
      break;
    case 2: // Orange
      turnOnLights(255, 128, 0);
      break;
    case 3: // Yellow
      turnOnLights(255, 255, 0);
      break;
    case 4: // Green
      turnOnLights(0, 128, 0);
      break;
    case 5: // Blue
      turnOnLights(0, 0, 205);
      break;
    case 6: // Purple
      turnOnLights(128, 0, 255);
      break;
    case 7: // Pink
      turnOnLights(128, 0, 128);
      break;
    default: // Otherwise, turn off the LED
      turnOffLights();
      break;
  }
}

// This function turns on the RGB LED to a colour specified by the 'red', 'green', and 'blue' parameters
void turnOnLights(int red, int green, int blue)
{
  analogWrite(ledPinRed, red);
  analogWrite(ledPinGreen, green);
  analogWrite(ledPinBlue, blue);
}

// This function turns off the RGB LED
void turnOffLights()
{
    analogWrite(ledPinRed, 0);
    analogWrite(ledPinGreen, 0);
    analogWrite(ledPinBlue, 0);
}
