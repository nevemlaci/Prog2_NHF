#include "init.hpp"

 //example initialization

namespace SGE2 {
	Game* init() {
		Game* game = new Game("title");
#ifndef CPORTA
		game->GetRenderer().SetRenderDrawColor(0, 100, 140, 255); //manually get an SDL component from the game
		game->GetAssetManager().AddTexture("testtexture", "test.png"); //load an asset using the asset manager
#endif
		g1& g = game->AddGameObject<g1>("g1"); //Add the gameobject and get a reference to it from the game	 (for testing)
#ifndef CPORTA
		game->AddGameObject<renderobject>("testrenderobject", Vector2(0, 0), Vector2(100, 100)); //add a 
#endif
		return game;
	}
}