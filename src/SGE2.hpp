/*Base*/
#include "Game.hpp"
#include "GameObject.hpp"
#include "Component.hpp"
#include "Transform.hpp"
#include "Vector2.hpp"

/*Built in components*/
#include "RendererComponent.hpp"
#include "WorldRendererComponent.hpp"
#include "UDCharacterController.hpp"

/*Simplify types*/
using SGL2::Game;
using SGL2::GameObject;
using SGL2::Component;
using SGL2::Vector2;
using SGL2::Transform;
#ifndef CPORTA
using SGL2::RendererComponent;
using SGL2::WorldRendererComponent;
using SGL2::UDCharacterController;
#endif

