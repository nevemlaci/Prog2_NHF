#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include "Game.hpp"
#include "GameObject.hpp"
#include "Component.hpp"
#include "RendererComponent.hpp"
#include "UDCharacterController.hpp"
#include <iostream>

#ifndef CPORTA

#endif

using SGE2::GameObject;
using SGE2::Vector2;
using SGE2::Component;
using SGE2::Game;
#ifndef CPORTA
using SGE2::RendererComponent;
using SGE2::UDCharacterController;
#endif

class c1 : public Component {
public:
	c1(GameObject& gameobject, const std::string& id) : Component(gameobject, id) {}

	void Startup(Game& game) override {
#ifndef CPORTA
		//m_RootGameObject.GetRoot().GetInputManager().AddMacro("wpress", "W");
#endif
		std::cout << this->m_Id << '\n';
	}
	void Update(Game& game) override {
#ifndef CPORTA
		/*
		if (m_RootGameObject.GetRoot().GetInputManager().Get("wpress")) {
			std::cout << "\nW pressed\n";
		}
		*/
#endif
	}
};

class c2 : public Component {
	//this does nothing it's just here for the unit tests
};

#ifndef CPORTA
class ControllerScript : public Component {
public:
	ControllerScript(GameObject& gameobject, const std::string& id) : Component(gameobject, id) {}

	void Startup(Game& game) override {
#ifndef CPORTA
		m_RootGameObject.GetRoot().GetInputManager().AddMacro("up", "W");
		m_RootGameObject.GetRoot().GetInputManager().AddMacro("down", "S");
		m_RootGameObject.GetRoot().GetInputManager().AddMacro("left", "A");
		m_RootGameObject.GetRoot().GetInputManager().AddMacro("right", "D");
#endif
		std::cout << this->m_Id << '\n';
	}
	void Update(Game& game) override {
#ifndef CPORTA
		Vector2 mov = Vector2(0, 0);
		if (m_RootGameObject.GetRoot().GetInputManager().Get("up")) {
			mov.y -= 5;
		}
		if (m_RootGameObject.GetRoot().GetInputManager().Get("down")) {
			mov.y += 5;
		}
		if (m_RootGameObject.GetRoot().GetInputManager().Get("left")) {
			mov.x -= 5;
		}
		if (m_RootGameObject.GetRoot().GetInputManager().Get("right")) {
			mov.x += 5;
		}

		m_RootGameObject.GetComponent<UDCharacterController>().Move(mov);
#endif
	}
};
#endif

class g1 : public GameObject {
public:
	//All GameObject constructors need to take at least a SGE2::Game& and a const std::string&
	g1(Game& game, const std::string& id) : GameObject(game, id, Vector2(0, 0), Vector2(0, 0), 0) {
		AddComponent<c1>("c1");
		AddComponent<c1>("cid");
	}
};
#ifndef CPORTA
class renderobject : public GameObject {
public:
	renderobject(Game& game, const std::string& id, const Vector2& pos, const Vector2& size) :
		GameObject(game, id, pos, size, 0) {
		AddComponent<RendererComponent>("renerercomponent", "testtexture");
		AddComponent<UDCharacterController>("charactercontroller");
		AddComponent<ControllerScript>("controllerscript");
	}
};
#endif


#endif