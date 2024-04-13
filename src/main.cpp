#include <Windows.h>
#include <iostream>
#include "GameObject.hpp"
#include "Game.hpp"
#include "init.hpp"

using SGE2::Game;

int main() {
	Game* game = SGE2::init();
	game->Run();

	delete game;
	return 0;
}