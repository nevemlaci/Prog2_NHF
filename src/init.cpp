#include "init.hpp"

 //example initialization

namespace SGL2 {
	Game* init() {
		Game* game = new Game("title");
#ifndef CPORTA
		//manual SDL access example
		game->GetRenderer().SetRenderDrawColor(0, 100, 140, 255); 
		//load assets using the asset manager
		game->GetAssetManager().AddTexture("charactertexture", "player.png");
		game->GetAssetManager().AddTexture("background", "background.jpeg");
		game->GetAssetManager().AddTexture("dummytexture", "meteor.png");
#endif
		//Add a dummy game object for unit testing 
		g1& g = game->AddGameObject<g1>("g1");

		//this is here to avoid unused variable warnings xd
		g.GetComponent<c1>(); 

#ifndef CPORTA
		//add bunch of test objects
		game->AddGameObject<background>("testbackgroundobject");
		game->AddGameObject<dummy>("dummy1", Vector2(100, 400));
		game->AddGameObject<dummy>("dummy2", Vector2(400, 800), Vector2(100, 50));
		game->AddGameObject<renderobject>("testrenderobject", Vector2(0, 0), Vector2(100, 100)); 
#endif
		return game;
	}
}