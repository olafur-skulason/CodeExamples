/*
 * MainGameLoop.h
 *
 *  Created on: Feb 28, 2020
 *      Author: olafur
 */

#ifndef INC_MAINGAMELOOP_H_
#define INC_MAINGAMELOOP_H_

#include "../inc/InputControl.h"
#include "../inc/GameState.h"
#include "../inc/ColorSelector.h"

typedef enum game_state {
	GAME_STATE_INITIALIZING = 0,
	GAME_STATE_PLAYING,
	GAME_STATE_GAME_FINISH
} GAME_STATE_T;

class MainGameLoop {
public:
	MainGameLoop(unsigned int codeLength, unsigned int attemptLimit, InputControl * inputCtrl, GameState * gameState);
	virtual ~MainGameLoop();
	int GameLoop();
private:
	bool finished;
	GAME_STATE_T current_state;
	unsigned int code_length;
	unsigned int attempt_limit;
	InputControl * input_control;
	GameState * game_state;

	void PlayGame();
};

#endif /* INC_MAINGAMELOOP_H_ */
