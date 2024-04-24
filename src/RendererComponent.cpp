// RendererComponent.cpp

#include "RendererComponent.hpp"
#include "Game.hpp"
#include "GameObject.hpp"

#ifndef CPORTA

#endif

namespace SGL2 {
#ifndef CPORTA
	RendererComponent::RendererComponent(GameObject& root, 
		const std::string& id, 
		const std::string& asset_name,
		int scaleX, int scaleY,
		int offsetX, int offsety) :
		Component(root, id),
		m_OffsetX(offsetX),
		m_OffsetY(offsety),
		m_ScaleX(scaleX),
		m_ScaleY(scaleY),
		m_Texture(root.GetRoot().GetAssetManager().GetTexture(asset_name)) 
	{}

	void RendererComponent::Startup(Game& game)  {
		std::cout << "\tAdded RendererComponent(id: " << m_Id << ") to " << m_RootGameObject.GetId() << '\n';
	}

	void RendererComponent::Update(Game& game) {
		game.GetRenderer() << SDL::at({ 
			m_RootGameObject.transform.position.x + m_OffsetX, 
			m_RootGameObject.transform.position.y + m_OffsetY, 
			m_RootGameObject.transform.size.x * m_ScaleX, 
			m_RootGameObject.transform.size.y * m_ScaleY})
			<< m_Texture;
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
