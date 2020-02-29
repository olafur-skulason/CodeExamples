/*
 * ColorSelector.h
 *
 *  Created on: Feb 28, 2020
 *      Author: olafur
 */

#ifndef INC_COLORSELECTOR_H_
#define INC_COLORSELECTOR_H_

class ColorSelector {
public:
	ColorSelector(unsigned int active_colors);
	virtual ~ColorSelector();

	char GetColor(unsigned int color);
	char GetRandomColor();
	unsigned int GetActiveColorCount();

	bool IsValidColor(char color);

private:
	char active_colors;
};

#endif /* INC_COLORSELECTOR_H_ */
