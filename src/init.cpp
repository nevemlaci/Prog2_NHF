#include "init.hpp"
#include "example.hpp" //example game object + component classes

namespace SGE2 {
	Game* init() {
		Game* game = new Game("title");
		GameObject& g = game->AddGameObject<g1>("g1"); //Add the gameobject and get a reference to it from the game

		c1& c = g.GetComponent<c1>(); //Get component only by type

		c1& cid = g.GetComponent<c1>("cid"); //Get component by type + id
		return game;
	}
}