#include "init.hpp"

 //example initialization

namespace SGL2 {
	void init() {
#ifndef CPORTA
		//manual SDL access example
		Game().GetRenderer().SetRenderDrawColor(0, 100, 140, 255); 
		//load assets using the asset manager
		AssetManager().AddTexture("charactertexture", "player.png");
		AssetManager().AddTexture("background", "background.jpeg");
		AssetManager().AddTexture("dummytexture", "meteor.png");
#endif
		//Add a dummy game object for unit testing 
		g1& g = Game().AddGameObject<g1>("g1");

		//this is here to avoid unused variable warnings xd
		g.GetComponent<c1>(); 

#ifndef CPORTA
		//add bunch of test objects
		Game().AddGameObject<background>("testbackgroundobject");
		Game().AddGameObject<dummy>("dummy1", Vector2(100, 400));
		Game().AddGameObject<dummy>("dummy2", Vector2(400, 800), Vector2(100, 50));
		Game().AddGameObject<renderobject>("testrenderobject", Vector2(0, 0), Vector2(100, 100));
#endif
		
	}
}