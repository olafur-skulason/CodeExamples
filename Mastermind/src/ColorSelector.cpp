/*
 * ColorSelector.cpp
 *
 *  Created on: Feb 28, 2020
 *      Author: olafur
 */

#include "../inc/ColorSelector.h"

#include <stdlib.h>

const char COLOR_PALETTE[] = {'R', 'G', 'B', 'Y', 'W', 'B'};

ColorSelector::ColorSelector(unsigned int activeColors) :
	active_colors(activeColors) {

}

ColorSelector::~ColorSelector() {
	// TODO Auto-generated destructor stub
}

char ColorSelector::GetColor(unsigned int color) {
	return COLOR_PALETTE[color];
}

char ColorSelector::GetRandomColor() {
	return GetColor(rand() % active_colors);
}

unsigned int ColorSelector::GetActiveColorCount() {
	return active_colors;
}

bool ColorSelector::IsValidColor(char color) {
	for(int i = 0; i < active_colors; i++) {
		if(color == COLOR_PALETTE[i])
			return true;
	}
	return false;
}
