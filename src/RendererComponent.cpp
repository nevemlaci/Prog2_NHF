// RendererComponent.cpp

#include "RendererComponent.hpp"
#include "Game.hpp"
#include "GameObject.hpp"

#ifndef CPORTA

#endif

namespace SGE2 {
	RendererComponent::RendererComponent(GameObject& root, const char* id, const SDL::Texture& texture, int scaleX, int scaleY, int offsetX, int offsety) :
		Component(root, id),
		m_OffsetX(offsetX),
		m_OffsetY(offsety),
		m_ScaleX(scaleX),
		m_ScaleY(scaleY),
#ifndef CPORTA
		m_TexturePtr(std::make_shared<SDL::Texture>(texture)) {
#endif
	}
#ifndef CPORTA
	void RendererComponent::Startup(Game& game)  {

	}

	void RendererComponent::Update(Game& game) {
		game.GetRenderer() << SDL::at({ m_RootGameObject.transform.position.x, m_RootGameObject.transform.position.x, m_RootGameObject.transform.size.x, m_RootGameObject.transform.size.y });
	}
#endif

#ifdef CPORTA
	
#endif

}
