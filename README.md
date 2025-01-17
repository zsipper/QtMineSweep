
# Intro
This is a personal project to demonstrate ability with C++/Qt.
Professionally, I am used to coding with Visual Studio. CMake to build the project solution and link external libraries such as Qt.
However, I am using this project as an opportunity to use Qt Creator. I haven't used this IDE/environment before. It is MUCH faster to spin up a new project from nothing.

This repo is a Qt Creator Project representing a C++/Qt minesweeper clone.

# Disclaimer
This project is a work-in-progress. It is missing key game state functionality.

## What it DOES have:
- main menu featuring difficulty selection
- model classes to generate and store the game and associated mine field
- widget class for the game mine field
- on-click logic for the minefield grid

## What is DOES NOT have:
- mine flagging functionality
- game state management, e.g. click mine -> game over
- app exit button
- return to menu menu button
- score tracking
- styling, other than default

# Execution
Simply clone this repo somehwere onto your machine
If you do not have Qt Creator, download Qt Creator Community Edition
When you are in Qt Creator, select 'Open Project', navigate to the local clone of this repo, and slect the `QtMineSweep.pro` file
Execute the project by clicking the green play or run button.s
