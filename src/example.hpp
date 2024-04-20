#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include "Game.hpp"
#include "GameObject.hpp"
#include "Component.hpp"
#include "RendererComponent.hpp"
#include <iostream>

#ifndef CPORTA

#endif

using SGE2::GameObject;
using SGE2::Vector2;
using SGE2::Component;
using SGE2::Game;
using SGE2::RendererComponent;

class c1 : public Component {
public:
	c1(GameObject& gameobject, const std::string& id) : Component(gameobject, id) {}

	void Startup(Game& game) override {
		std::cout << this->m_Id << '\n';
	}
	void Update(Game& game) override {

	}
};

class c2 : public Component {
	//this does nothing it's just here for the unit tests
};

class g1 : public GameObject {
public:
	//All GameObject constructors need to take at least a SGE2::Game& and a const std::string&
	g1(Game& game, const std::string& id) : GameObject(game, id, Vector2(0, 0), Vector2(0, 0), 0) {
		AddComponent<c1>("c1");
		AddComponent<c1>("cid");
	}
};

class renderobject : public GameObject {
public:
	renderobject(Game& game, const std::string& id, const Vector2& pos, const Vector2& size) :
		GameObject(game, id, pos, size, 0) {
		AddComponent<RendererComponent>("renerercomponent", "testtexture");
	}
};

#endif