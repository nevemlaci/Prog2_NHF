#include <Windows.h>
#include <iostream>
#include "GameObject.hpp"
#include "Game.hpp"
#undef main

using SGE2::GameObject;
using SGE2::Vector2;
using SGE2::Component;
using SGE2::Game;

class c1 : public Component{
public:
	c1(GameObject* gameobject, const char* id) : Component(gameobject, id) {}

	void Startup(Game& game) override {
		game.GetRenderer().SetRenderDrawColor(0, 0, 255, 255);

	}
	void Update(Game& game) override {
		game.GetRenderer().RenderClear();
		game.GetRenderer().SetRenderDrawColor(255, 0, 0, 255);
		game.GetRenderer().FillRect(SDL::Rect(0, 0, 50, 50));
		game.GetRenderer().RenderPresent();
		game.GetRenderer().SetRenderDrawColor(0, 0, 255, 255);
	}
};

class g1 : public GameObject {
public:
	g1() : GameObject(Vector2(0, 0), Vector2(0, 0), 0){
		AddComponent<c1>("asd");
	}
	
};

int main() {
	Game game("testtitle");

	GameObject& g = game.AddGameObject<g1>();

	game.Run();
	return 0;
}