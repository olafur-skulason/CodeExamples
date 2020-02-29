/*
 * GameState_test.cpp
 *
 *  Created on: Feb 28, 2020
 *      Author: olafur
 */

#include <gtest/gtest.h>

#include "../inc/GameState.h"
#include "../inc/ColorSelector.h"



TEST(GameState, Initialization) {
	ColorSelector cs = ColorSelector(4); // TODO: This should be replaced with a mock.
	GameState game_state = GameState(4,4, &cs);

	ASSERT_EQ(game_state.GetBlackPegs(), 0);
	ASSERT_EQ(game_state.GetWhitePegs(), 0);
	ASSERT_EQ(game_state.GetMasterCode(), nullptr);

	game_state.Initialize();

	ASSERT_EQ(game_state.GetBlackPegs(), 0);
	ASSERT_EQ(game_state.GetWhitePegs(), 0);
	ASSERT_NE(game_state.GetMasterCode(), nullptr);

}

TEST(GameState, GuessAndLose) {
	ColorSelector cs = ColorSelector(4); // TODO: This should be replaced with a mock.
	GameState game_state = GameState(4,1, &cs);

	game_state.Initialize();
	unsigned char * master_code = new unsigned char(4);
	master_code[0] = 'R';
	master_code[1] = 'R';
	master_code[2] = 'R';
	master_code[3] = 'R';
	game_state.SetMasterCode(master_code);

	unsigned char * guess_code = new unsigned char(4);
	guess_code[0] = 'R';
	guess_code[1] = 'G';
	guess_code[2] = 'G';
	guess_code[3] = 'G';
	game_state.InputGuess(guess_code);

	ASSERT_TRUE(game_state.IsFinished());
	ASSERT_EQ(game_state.GetBlackPegs(), (unsigned char)1);
	ASSERT_EQ(game_state.GetWhitePegs(), (unsigned char)0);
}

// To balance time requirements and coverage edge pair coverage is used.

// [0,1,2,5,6,7,6,7,6,4,1,9]
TEST(GameState, NoBlackNoWhite) {
	ColorSelector cs = ColorSelector(2); // TODO: This should be replaced with a mock.
	GameState game_state = GameState(1,8, &cs);

	game_state.Initialize();
	unsigned char * master_code = new unsigned char(4);
	master_code[0] = 'R';
	game_state.SetMasterCode(master_code);

	unsigned char * guess_code = new unsigned char(4);
	guess_code[0] = 'G';

	game_state.InputGuess(guess_code);

	ASSERT_FALSE(game_state.IsFinished());
	ASSERT_EQ(game_state.GetBlackPegs(), (unsigned char)0);
	ASSERT_EQ(game_state.GetWhitePegs(), (unsigned char)0);
}

// [0,1,2,5,6,7,6,7,8,4,1,9]
TEST(GameState, NoBlackOneWhite) {
	ColorSelector cs = ColorSelector(3); // TODO: This should be replaced with a mock.
	GameState game_state = GameState(2,8, &cs);

	game_state.Initialize();
	unsigned char * master_code = new unsigned char(4);
	master_code[0] = 'G';
	master_code[1] = 'R';
	game_state.SetMasterCode(master_code);

	unsigned char * guess_code = new unsigned char(4);
	guess_code[0] = 'Y';
	guess_code[1] = 'G';

	game_state.InputGuess(guess_code);

	ASSERT_FALSE(game_state.IsFinished());
	ASSERT_EQ(game_state.GetBlackPegs(), (unsigned char)0);
	ASSERT_EQ(game_state.GetWhitePegs(), (unsigned char)1);
}

// [0,1,2,3,4,1,2,5,6,4,1,9]
TEST(GameState, OneBlackNoWhite) {
	ColorSelector cs = ColorSelector(3); // TODO: This should be replaced with a mock.
	GameState game_state = GameState(2,8, &cs);

	game_state.Initialize();
	unsigned char * master_code = new unsigned char(4);
	master_code[0] = 'Y';
	master_code[1] = 'R';
	game_state.SetMasterCode(master_code);

	unsigned char * guess_code = new unsigned char(4);
	guess_code[0] = 'Y';
	guess_code[1] = 'G';

	game_state.InputGuess(guess_code);

	ASSERT_FALSE(game_state.IsFinished());
	ASSERT_EQ(game_state.GetBlackPegs(), (unsigned char)1);
	ASSERT_EQ(game_state.GetWhitePegs(), (unsigned char)0);
}
