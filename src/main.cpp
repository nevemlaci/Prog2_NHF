#include "GameObject.hpp"
#include "Game.hpp"
#include "init.hpp"


using SGE2::Game;

#undef main
int main() {
	Game* game = SGE2::init();
#ifndef CPORTA
	game->Run();
#endif

#ifdef CPORTA
	
#endif
	delete game;
	return 0;
}