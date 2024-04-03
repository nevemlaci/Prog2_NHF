#include <Windows.h>
#include <iostream>
#include "GameObject.hpp"

using SGE2::GameObject;
using SGE2::Vector2;
using SGE2::Component;

class c1 : public Component{
	c1(GameObject* gameobject, const char* id) : Component(gameobject, id) {}
};

int main() {
	GameObject g(Vector2(0, 0), Vector2(0, 0), 0);
	
	return 0;
}