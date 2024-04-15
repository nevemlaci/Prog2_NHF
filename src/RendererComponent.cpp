// RendererComponent.cpp

#include "RendererComponent.hpp"
#include "Game.hpp"
#include "GameObject.hpp"

#ifndef CPORTA

#endif

namespace SGE2 {
#ifndef CPORTA
	RendererComponent::RendererComponent(GameObject& root, 
		const std::string& id, 
		const SDL::Texture&,
		int scaleX, int scaleY,
		int offsetX, int offsety) :
		Component(root, id),
		m_OffsetX(offsetX),
		m_OffsetY(offsety),
		m_ScaleX(scaleX),
		m_ScaleY(scaleY),
		m_TexturePtr(std::make_shared<SDL::Texture>(texture)) 
	{}

	void RendererComponent::Startup(Game& game)  {

	}

	void RendererComponent::Update(Game& game) {
		game.GetRenderer() << SDL::at({ m_RootGameObject.transform.position.x, m_RootGameObject.transform.position.x, m_RootGameObject.transform.size.x, m_RootGameObject.transform.size.y });
	}
#endif

#ifdef CPORTA
	RendererComponent::RendererComponent(
		GameObject& root, 
		const std::string& id,
		int scaleX, 
		int scaleY,
		int offsetX, 
		int offsety
	) :
		Component(root, id),
		m_OffsetX(offsetX),
		m_OffsetY(offsety),
		m_ScaleX(scaleX),
		m_ScaleY(scaleY)
	{
		
	}


	void RendererComponent::Startup(Game& game) {
		std::cout << "\t\t RenderComponent: Cporta detected. This RendererComponent is attached to GameObject with id: " << m_RootGameObject.GetId() << '\n'; //We don't render anything if we are on CPORTA xd
	}
	void RendererComponent::Update(Game& game) {
		
	}
#endif

}
