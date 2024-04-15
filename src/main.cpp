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

	/*Test the gameobject getter*/
	g1& testobj = game->GetGameObject<g1>("g1");
	TEST(Game, GetGameObject) { //also confirms that the game object getter is working
		EXPECT_EQ(testobj.GetId(), std::string("g1")/*convert to std::string to be sure*/);
	}END

	/*Test the gameobject getter exception*/
	TEST(Game, GetNonExistentGameObject) {
	EXPECT_THROW(
		game->GetGameObject("object_with_this_id_does_not_exist"),
		std::runtime_error);
	}END


	/*Test the component getter*/
	c1& testcomp = testobj.GetComponent<c1>();
	TEST(GameObject, GetComponentByTypeOnly) {
		EXPECT_EQ(testcomp.GetId(), std::string("c1") /*the first component had the id "c1"*/);
	}END

	/*No component with type 'c2' is attached to 'testobj'*/
	TEST(GameObject, GetNonExistentComponentById) {
		EXPECT_THROW(testobj.GetComponent<c2>(), std::runtime_error);
	}END
	




#endif
	delete game;
	std::cerr << "\n\n\nInput any character to exit...\n";
	std::cin.get(); //block Mr Memory from exiting instantly

	return 0;
}