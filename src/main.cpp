#include "GameObject.hpp"
#include "Game.hpp"
#include "init.hpp"
#include <gtest_lite.h>
#include <iostream>


using SGE2::Game;
using SGE2::GameObject;
using SGE2::Component;

#undef main
int main() {
	Game* game = SGE2::init();
#ifndef CPORTA
	game->Run();
#endif

#ifdef CPORTA

	g1& testobj = game->GetGameObject<g1>("g1");
	TEST(Game, GetGameObject) { //also confirms that the game object getter is working
		EXPECT_EQ(testobj.GetId(), "g1");
	}END
	
	TEST(Game, GetNonExistentGameObject) {
		EXPECT_THROW(
			game->GetGameObject("object_with_this_id_does_not_exist"), 
			std::runtime_error);
	}END
	

	



#endif
	delete game;
	std::cerr << "Input any character to exit!\n";
	std::cin.get(); //block Mr Memory from exiting instantly

	return 0;
}