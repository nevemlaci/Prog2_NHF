#include "init.hpp"
 //example game object + component classes

namespace SGE2 {
	Game* init() {
		Game* game = new Game("title");
		game->GetAssetManager().AddTexture("testtexture", "test.png");
		g1& g = game->AddGameObject<g1>("g1"); //Add the gameobject and get a reference to it from the game	
		game->AddGameObject<renderobject>("testrenderobject", Vector2(0, 0), Vector2(100, 100));
		return game;
	}
}