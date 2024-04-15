// RendererComponent.hpp

#ifndef __RendererComponent_H__
#define __RendererComponent_H__

#include "Component.hpp"
#include <iostream>

#ifndef CPORTA
#include "cpp_SDL_include.hpp"
#endif

namespace SGE2 {
class RendererComponent final : public Component {
public:
#ifndef CPORTA
	RendererComponent(
		GameObject& root, const std::string& id, const SDL::Texture&,
		int scaleX=0, int scaleY=0,
		int offsetX = 0, int offsety = 0
	);
#endif
#ifdef CPORTA
	RendererComponent(
		GameObject& root, const std::string& id,
		int scaleX = 0, int scaleY = 0,
		int offsetX = 0, int offsety = 0
	);
#endif 

	
	void Startup(Game& game) override;
	void Update(Game& game) override;

#ifndef CPORTA

#endif

#ifdef CPORTA

#endif

private:
	int m_OffsetX;
	int m_OffsetY;
	int m_ScaleX;
	int m_ScaleY;
#ifndef CPORTA
	std::shared_ptr<SDL::Texture> m_TexturePtr;
#endif

#ifdef CPORTA

#endif
};
}
#endif


