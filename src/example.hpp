#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include "Game.hpp"
#include "GameObject.hpp"
#include "Component.hpp"
#undef main
#ifndef CPORTA

#endif

using SGE2::GameObject;
using SGE2::Vector2;
using SGE2::Component;
using SGE2::Game;

class c1 : public Component {
public:
	c1(GameObject* gameobject, const char* id) : Component(gameobject, id) {}

	void Startup(Game& game) override {
		std::cout << this->m_Id << '\n';
#ifndef CPORTA
		game.GetRenderer().SetRenderDrawColor(0, 0, 255, 255);
#endif
	}
	void Update(Game& game) override {
#ifndef CPORTA
		game.GetRenderer().RenderClear();
		game.GetRenderer().SetRenderDrawColor(255, 0, 0, 255);
		game.GetRenderer().FillRect(SDL::Rect(0, 0, 50, 50));
		game.GetRenderer().RenderPresent();
		game.GetRenderer().SetRenderDrawColor(0, 0, 255, 255);
#endif
	}
};

class g1 : public GameObject {
public:
	//All GameObject constructors need to take at least a reference to a SGE2::Game
	g1(Game& game, const char* id) : GameObject(game, id, Vector2(0, 0), Vector2(0, 0), 0) {
		AddComponent<c1>("c1");
		AddComponent<c1>("cid");
	}
};

#endif