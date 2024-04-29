#include "init.hpp"

 //example initialization

namespace SGL2 {
	Game* init() {
		Game* game = new Game("title");
#ifndef CPORTA
		game->GetRenderer().SetRenderDrawColor(0, 100, 140, 255); //manually get an SDL component from the game
		game->GetAssetManager().AddTexture("charactertexture", "test.png"); //load an asset using the asset manager
		game->GetAssetManager().AddTexture("background", "bg.png");
		game->GetAssetManager().AddTexture("dummytexture", "dummy.png");
#endif
		g1& g = game->AddGameObject<g1>("g1"); //Add the gameobject and get a reference to it from the game	 (for testing)

		g.GetComponent<c1>();

#ifndef CPORTA
		game->AddGameObject<background>("testbackgroundobject");
		game->AddGameObject<dummy>("dummy1", Vector2(100, 400));
		game->AddGameObject<dummy>("dummy2", Vector2(400, 800), Vector2(100, 50));
		game->AddGameObject<renderobject>("testrenderobject", Vector2(0, 0), Vector2(100, 100)); 
#endif
		return game;
	}
}