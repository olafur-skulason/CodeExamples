/*
 * MainGameLoop.cpp
 *
 *  Created on: Feb 28, 2020
 *      Author: olafur
 */

#include "../inc/MainGameLoop.h"

#include <iostream>

MainGameLoop::MainGameLoop(unsigned int codeLength, unsigned int attemptLimit, InputControl * inputCtrl, GameState * gameState)
	: finished(false),
	  current_state(GAME_STATE_INITIALIZING),
	  code_length(codeLength),
	  attempt_limit(attemptLimit),
	  input_control(inputCtrl),
	  game_state(gameState)
{
}

MainGameLoop::~MainGameLoop() {
}

int MainGameLoop::GameLoop() {
	try
	{
		while(!finished) {
			std::cout << "Current state: " << current_state << std::endl;
			switch (current_state) {
			case GAME_STATE_INITIALIZING:
				// Initialize components.
				current_state = GAME_STATE_PLAYING;
				game_state->Initialize();
				break;
			case GAME_STATE_PLAYING:
				PlayGame();
				break;
			case GAME_STATE_GAME_FINISH:
				if (input_control->Restart())
				{
					current_state = GAME_STATE_INITIALIZING;
				}
				else
				{
					finished = true;
				}
				break;
			}
		}
		return 0;
	}
	catch(const char * message)
	{
		std::cout << message << std::endl;
		return 1;
	}
}

void MainGameLoop::PlayGame() {
	unsigned char * guess = nullptr;
	guess = input_control->GetNextGuess(code_length);
	game_state->InputGuess(guess);
	if (game_state->IsFinished())
	{
		input_control->PrintVictoryMessage();
		current_state = GAME_STATE_GAME_FINISH;
	}
	else
	{
		input_control->PrintGuessHints(game_state->GetBlackPegs(), game_state->GetWhitePegs());
		current_state = GAME_STATE_PLAYING;
	}
	delete guess;
}

/*
int main() {
	ColorSelector colorSelect = ColorSelector(4);
	InputControl inputCtrl = InputControl(& colorSelect);
	GameState gameState = GameState(4, 8, & colorSelect);
	return MainGameLoop(4, 8, & inputCtrl, & gameState).GameLoop();
	std::cout << "Thank you for playing" << std::endl;
}*/
