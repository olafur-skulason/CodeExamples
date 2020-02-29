/*
 * GameState.h
 *
 *  Created on: Feb 28, 2020
 *      Author: olafur
 */

#ifndef INC_GAMESTATE_H_
#define INC_GAMESTATE_H_

#include "../inc/ColorSelector.h"

class GameState {
public:
	GameState(unsigned int codeLength, unsigned int attemptLimit, ColorSelector * colorSelector);
	virtual ~GameState();

	void Initialize();
	bool IsFinished();
	void InputGuess(unsigned char * guess);
	unsigned char GetWhitePegs();
	unsigned char GetBlackPegs();
	unsigned char * GetMasterCode();
	void SetMasterCode(unsigned char * new_code);
private:
	ColorSelector * color_selector;
	unsigned int code_length;
	unsigned int attempt_limit;
	unsigned int attempts;
	unsigned char * master_code;
	unsigned char black;
	unsigned char white;

	unsigned char * GenerateMasterCode();
	int CountColor(unsigned char * guess, char color);
};

#endif /* INC_GAMESTATE_H_ */
