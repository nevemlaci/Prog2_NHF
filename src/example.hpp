#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include "SGL2.hpp"
#include <iostream>

#ifndef CPORTA

#endif


class c1 : public Component {
public:
	c1(GameObject& gameobject, const std::string& id) : Component(gameobject, id) {}
	void Startup(Game_t& game) override {

		std::cout << this->m_Id << '\n';
	}
	void Update(Game_t& game) override {
	}
};

class c2 : public Component {
	//this does nothing it's just here for the unit tests
};

#ifndef CPORTA
class ControllerScript : public Component {
public:
	ControllerScript(GameObject& gameobject, const std::string& id) : Component(gameobject, id) {}

	void Startup(Game_t& game) override {
		
		std::cout << this->m_Id << '\n';
	}
	void Update(Game_t& game) override {
		//link the camera to the player
		
		Game().GetMainCamera().transform.SetPositionByMiddle(this->m_RootGameObject.transform.Middle());

		//check for the macros that we added
		Vector2 mov = Vector2(0, 0);
		if (InputManager().Get("up")) {
			mov.y -= 1;
		}
		if (InputManager().Get("down")) {
			mov.y += 1;
		}
		if (InputManager().Get("left")) {
			mov.x -= 1;
		}
		if (InputManager().Get("right")) {
			mov.x += 1;
		}

		//Move by the normalized vector
		m_RootGameObject.GetComponent<UDCharacterController>().Move(m_MoveSpeed * mov.normalized() * (Time().DeltaTime() / Time().ratio));


	}
private:
	float m_MoveSpeed = 330.0;
};
#endif

class g1 : public GameObject {
public:
	//All GameObject constructors need to take at least a SGE2::Game& and a const std::string&
	g1(Game_t& game, const std::string& id) : GameObject(game, id, Vector2(0, 0), Vector2(0, 0), 0) {
		AddComponent<c1>("c1");
		AddComponent<c1>("cid");
	}
};


#ifndef CPORTA
class renderobject : public GameObject {
public:
	renderobject(Game_t& game, const std::string& id, const Vector2& pos, const Vector2& size) :
		GameObject(game, id, pos, size, 0) {
		AddComponent<RendererComponent>("character", "charactertexture");
		AddComponent<UDCharacterController>("charactercontroller");
		AddComponent<ControllerScript>("controllerscript");
	}
};

class background : public GameObject {
public:
	background(Game_t& game, const std::string& id) : GameObject(game, id, Vector2(0, 0), game.GetScreenSize(), 0) {
		AddComponent<UIRendererComponent>("worldrenderercomponent", "background");
	}
};

class dummy : public GameObject {
public:
	dummy(Game_t& game, const std::string& id, const Vector2& pos, const Vector2& size = Vector2(50, 50)) : GameObject(game, id, pos, size, 0) {
		AddComponent<RendererComponent>("dummy", "dummytexture");
	}
};

#endif


#endif