#include "init.hpp"
 //example game object + component classes

namespace SGE2 {
	Game* init() {
		Game* game = new Game("title");
		
		g1& g = game->AddGameObject<g1>("g1"); //Add the gameobject and get a reference to it from the game	

		return game;
	}
}