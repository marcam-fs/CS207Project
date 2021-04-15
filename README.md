# CS207Project: Interactive Gesture-Controlled Table Light

## Table of Contents
1. Manifest
2. Features
3. Reproduction
4. Usage
5. Planned Features
6. Bugs
7. License
8. Credits

## Manifest
This repository contains the following items:
- [READme.md](docs/README.md): The file you are currently reading, containing a detailed description of this project.
- [mariaAzam_CS207Project.ino](docs/mariaAzam_CS207Project): The Arduino source code for this project.

## Features
This project creates an interactive gesture-controlled table light. The table light features two main components: light and sound, and is composed of five IR Sensors, one RGB LED, and one piezo speaker. The table light is controlled by 'swiping' movements, the movement of a hand from right to left, detected by the IR Sensors. There is a series of 8 possible swipes of the hand, each swipe number corresponding to a different behaviour of the table light. Initially, the table light will be off. Once the first hand swipe is detected, the table light will turn on, indicated by a red LED and the 'Super Mario Bros' song playing from the piezo speaker. The second hand swipe will result in an orange LED and the 'The Lion Sleeps Tonight Song.' The colour of the LED and song will continue to change 5 more times, for a total of 7 different colours and songs. The eighth and final swipe will turn the table light off, indicated by no light in the RGB LED and no song playing rom the piezo speaker.

The following colours and songs are included in each swipe of the table light:
1. Red, 'Overworld Theme' - Super Mario Bros
2. Orange, 'The Lion Sleeps Tonight'
3. Yellow, 'Asa Branca' - Luiz Gonzaga
4. Green, 'Hedwig's Theme' - Harry Potter
5. Blue, 'Game of Thrones Theme' - Game of Thrones
6. Purple, 'Song of Storms' - Legend of Zelda Ocarina of Time
7. Pink, 'Pink Panther Theme' - Pink Panther
8. No colour, no music

For a more detailed visual and audial description of the project, please view the video here:
[INSERT YOUTUBE VIDEO LINK](YOUTUBE VIDEO LINK)

## Reproduction
In order to reproduce this project, you will need the following hardware components:
- 1 Arduino Uno (complete with a USB cable)
- Jumper Wires (at least 21)
- 5 IR Sensors (you may use more or less, or even an IR Sensor, array if you choose)
- 1 RGB LED
- 1 Piezo Speaker

To build the circuit, arrange the above-mentioned hardware components according to the following schematic diagram:
INSERT DIAGRAM HERE

To build the software for this project, please complete the following steps:
- Download and open the Arduino software for your specific operating system. For specific download instructions and versions, please visit: [Arduino Software](https://www.arduino.cc/en/software).
- When you open Arduino, a new project will be created for you. Save it in your desired location on your device.
- You will see that a code template has been created for you. Delete this and add the required code for this project. Either copy/paste or download the following source code [mariaAzam_CS207Project.ino](docs/mariaAzam_CS207Project.ino) into your `.ino` file.
- In order for the `music` functions to work, you will need to install the 'MusicBuzzer' library by [robsoncouto](https://github.com/robsoncouto/arduino-songs). To do so, please complete the following steps:
  - In the top toolbar of Arduino, select: `Sketch > Include Library > Manage Libraries`.
  - In the `Library Manager` dialog box, search for 'Music Buzzer'.
  - Select the `MusicBuzzer` library by Everton Ramires, and click `Install`.
  - Save this library in your `Documents > Arduino > libraries` folder on your device.
  - Once the `MusicBuzzer` library has been installed, you need to add it to your project.
  - In the top toolbar of Arduino, select: `Sketch > Include Library > Add .ZIP Library...`.
  - Navigate to your `Documents > Arduino > libraries` folder, select `MusicBuzzer`, and press `Choose`.
  - Arduino will automatically add a `#include <MusicBuzzer.h>` statement at the top of your code. This is necessary, so do not alter or erase it.
  - Now the `MusicBuzzer` library has been included in your project, and you are ready to use its functions.

## Usage

## Planned Features

## Bugs

## License

## Credits
