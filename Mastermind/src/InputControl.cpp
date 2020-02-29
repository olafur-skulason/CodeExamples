/*
 * InputControl.cpp
 *
 *  Created on: Feb 28, 2020
 *      Author: olafur
 */

#include "../inc/InputControl.h"

#include <iostream>
#include <string>

InputControl::InputControl(ColorSelector * colorSelector) : color_selector(colorSelector) {
	// TODO Auto-generated constructor stub

}

InputControl::~InputControl() {
	// TODO Auto-generated destructor stub
}

bool InputControl::Restart(){
	std::cout << "Do you wish to play another game? [Y/N]";
	std::string input;
	while(true) {
		try {
			getline(std::cin, input);
			if (input.compare("Y") == 0 || input.compare("y") == 0) {
				return true;
			}
			else if (input.compare("N") == 0 || input.compare("n") == 0) {
				return false;
			}
			else
				throw "Invalid Char.";
		}
		catch( ... ) {
			std::cout << "Invalid input, please try again. [Y/N]";
		}
	}
};

unsigned char * InputControl::GetNextGuess(unsigned int length) {
	std::cout << "Please enter your next guess [R/G/Y/B]" << std::endl;
	std::cout << "The code is of length: " << length << std::endl;
	std::cout << "The code shall be entered without any separators." << std::endl;
	std::string input;
	unsigned char * result = new unsigned char[length];
	while(true) {
		try {
			getline(std::cin, input);
			if(input.size() != length)
				throw "Incorrect length";

			const char * input_c_str = input.c_str();
			for(unsigned int i = 0; i < length; i++) {
				if(color_selector->IsValidColor(input_c_str[i])) {
					result[i] = input_c_str[i];
				}
				else
					throw "Invalid character.";
			}

			return result;
		}
		catch( ... ) {
			std::cout << "Invalid input, please try again. [R/G/Y/B]";
		}
	}
};


void InputControl::PrintVictoryMessage() {
	std::cout << "Congratulations, you have guessed the correct code." << std::endl;
}

void InputControl::PrintGuessHints(unsigned char black, unsigned char white) {
	std::cout << "Your guess was not correct" << std::endl;
	std::cout << "You have " << (unsigned int)black << " correct colors in the correct place (black pegs)" << std::endl;
	std::cout << "You have " << (unsigned int)white << " correct colors in the wrong place (white pegs)" << std::endl;
}

