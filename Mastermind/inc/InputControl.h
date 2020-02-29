/*
 * InputControl.h
 *
 *  Created on: Feb 28, 2020
 *      Author: olafur
 */

#ifndef INC_INPUTCONTROL_H_
#define INC_INPUTCONTROL_H_

#include "../inc/ColorSelector.h"

class InputControl {
public:
	InputControl(ColorSelector * colorSelector);
	virtual ~InputControl();

	virtual bool Restart();
	virtual unsigned char * GetNextGuess(unsigned int length);
	virtual void PrintVictoryMessage();
	virtual void PrintGuessHints(unsigned char black, unsigned char white);
private:
	ColorSelector * color_selector;
};

#endif /* INC_INPUTCONTROL_H_ */
