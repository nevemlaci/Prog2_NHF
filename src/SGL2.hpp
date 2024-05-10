/*Base*/
#include "Game.hpp"
#include "GameObject.hpp"
#include "Component.hpp"
#include "Transform.hpp"
#include "Vector2.hpp"
#include "Time.hpp"
#include "AssetManager.hpp"
#include "Input.hpp"

/*Built in components*/
#include "RendererComponent.hpp"
#include "UIRendererComponent.hpp"
#include "UDCharacterController.hpp"

/*Simplify names*/
using SGL2::Game;
using SGL2::Game_t;
using SGL2::GameObject;
using SGL2::Component;
using SGL2::Vector2;
using SGL2::Transform;
#ifndef CPORTA
using SGL2::RendererComponent;
using SGL2::UIRendererComponent;
using SGL2::UDCharacterController;
using SGL2::Time;
using SGL2::AssetManager;
using SGL2::InputManager;
#endif

