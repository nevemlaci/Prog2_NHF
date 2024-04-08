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

	void print() {
		std::cout << this->m_Id << '\n';
	}
};

class g1 : public GameObject {
public:
	g1() : GameObject(Vector2(0, 0), Vector2(0, 0), 0){
		AddComponent<c1>("c1");
		AddComponent<c1>("cid");
	}
};

int main() {
	Game game("testtitle");

	GameObject& g = game.AddGameObject<g1>(); //Add the gameobject and get a reference to it from the game
	
	c1& c = g.GetComponent<c1>(); //Get component only by type
	c.print();

	c1& cid = g.GetComponent<c1>("cid"); //Get component by type + id
	cid.print();

	game.Run();
	return 0;
}