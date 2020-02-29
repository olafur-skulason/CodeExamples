/*
 * ColorSelector_test.cpp
 *
 *  Created on: Feb 28, 2020
 *      Author: olafur
 */

#include <gtest/gtest.h>

#include "../inc/ColorSelector.h"

TEST(ColorSelector, IsValidColor) {
	ColorSelector colorSelector(4);

	bool r1 = colorSelector.IsValidColor('0');
	ASSERT_FALSE(r1);

	bool r2 = colorSelector.IsValidColor('W');
	ASSERT_FALSE(r2);

	bool r3 = colorSelector.IsValidColor('Y');
	ASSERT_TRUE(r3);
}
