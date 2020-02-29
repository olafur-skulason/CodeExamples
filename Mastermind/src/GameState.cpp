/*
 * GameState.cpp
 *
 *  Created on: Feb 28, 2020
 *      Author: olafur
 */

#include "../inc/GameState.h"

#include <iostream>

GameState::GameState(unsigned int codeLength, unsigned int attemptLimit, ColorSelector * colorSelector) :
	color_selector(colorSelector),
	code_length(codeLength),
	attempt_limit(attemptLimit),
	attempts(0),
	master_code(nullptr),
	black(0),
	white(0)
{
}

GameState::~GameState() {
	delete master_code;
}

void GameState::Initialize() {
	attempts = 0;
	master_code = GenerateMasterCode();
	black = 0;
	white = 0;
}

bool GameState::IsFinished() {
	if(black == code_length) {
		return true;
	}
	else if(attempts >= attempt_limit) {
		return true;
	}
	else {
		return false;
	}
}

unsigned char GameState::GetWhitePegs() {
	return white;
}

unsigned char GameState::GetBlackPegs() {
	return black;
}

unsigned char * GameState::GetMasterCode() {
	return master_code;
}

void GameState::SetMasterCode(unsigned char * new_code) {
	master_code = new_code;
}

void GameState::InputGuess(unsigned char * guess) {
	white = 0;
	black = 0;
	bool flag[code_length] = {false};
	for(unsigned int i = 0; i < code_length; i++) {
		if(guess[i] == master_code[i])
			black++;
		else {
			for(unsigned int j = 0; j < code_length; j++) {
				if (j != i && guess[i] == master_code[j] && !flag[j]) {
					white++;
					flag[j]=1;
					break;
				}
			}
		}
	}
	attempts++;
}

unsigned char * GameState::GenerateMasterCode() {
	if(master_code != nullptr)
		delete master_code;
	unsigned char * new_code = new unsigned char(code_length);

	std::cout << "Original master code: ";
	for(unsigned int i = 0; i < code_length; i++) {
		new_code[i] = color_selector->GetRandomColor();
		std::cout << new_code[i];
	}
	std::cout << std::endl;

	return new_code;
}

int GameState::CountColor(unsigned char * code, char color) {
	int result = 0;
	for(unsigned int i = 0; i < code_length; i++) {
		if(code[i] == color)
			result++;
	}
	return result;
}
