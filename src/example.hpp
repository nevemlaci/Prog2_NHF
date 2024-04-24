#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include "SGE2.hpp"
#include <iostream>

#ifndef CPORTA

#endif

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

#ifndef CPORTA
class ControllerScript : public Component {
public:
	ControllerScript(GameObject& gameobject, const std::string& id) : Component(gameobject, id) {}

	void Startup(Game& game) override {
		m_RootGameObject.GetRoot().GetInputManager().AddMacro("up", "W");
		m_RootGameObject.GetRoot().GetInputManager().AddMacro("down", "S");
		m_RootGameObject.GetRoot().GetInputManager().AddMacro("left", "A");
		m_RootGameObject.GetRoot().GetInputManager().AddMacro("right", "D");
		std::cout << this->m_Id << '\n';
	}
	void Update(Game& game) override {
		Vector2 mov = Vector2(0, 0);
		if (m_RootGameObject.GetRoot().GetInputManager().Get("up")) {
			mov.y -= 1;
		}
		if (m_RootGameObject.GetRoot().GetInputManager().Get("down")) {
			mov.y += 1;
		}
		if (m_RootGameObject.GetRoot().GetInputManager().Get("left")) {
			mov.x -= 1;
		}
		if (m_RootGameObject.GetRoot().GetInputManager().Get("right")) {
			mov.x += 1;
		}

		//Move by the normalized vector
		m_RootGameObject.GetComponent<UDCharacterController>().Move(m_MoveSpeed * mov.normalized());
	}
private:
	float m_MoveSpeed = 1;
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