# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg




# Student Contribution:
## Instructions for running the project: 
The section above, "Basic Build Instructions" covers this part.

## Overview of your code structure
This project consists of a snake game with an extra obstacle. The snake now has a competitor for the food. A class named "Human" was created by copying the Snake class and doing some changes. The human is a non-player character that eats the food just like the snake, this will make him grow and increase speed. Besides the competition for food, the snake can not touch the human or it will die and the game is over. The objective of the snake is to get the biggest score possible.


## Explanation of how your submission satisfies the necessary rubric
1. The project demonstrates an understanding of C++ functions and control structures. The project code is clearly organized into functions.

Example for 1 rubric:  controller.cpp lines 65-72, use of an auxilar function "DistanceBetweenTwoPoints" for distance calculation.


2. The project uses Object Oriented Programming techniques;
3. Classes use appropriate access specifiers for class members;
4. Class constructors utilize member initialization lists.

Example for 2,3,4 rubric: human.cpp/h



5. Classes encapsulate behavior.

Example for 4 rubric: human.h lines 35-41 methods "SetFoodLocation" and "GetFoodLocation" 



6. Templates generalize functions in the project:

Example for 5 rubric: controller.h, lines 12-13: "ChangeDirection" altered to be declared with a template to be used by both snake and human classes



       



