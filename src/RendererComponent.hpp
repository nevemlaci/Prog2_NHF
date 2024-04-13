// RendererComponent.hpp

#ifndef __RendererComponent_H__
#define __RendererComponent_H__

#include "Component.hpp"



#ifndef CPORTA
#include "cpp_SDL_include.hpp"
#endif

namespace SGE2 {
class RendererComponent : public Component {
public:
	RendererComponent(
		GameObject*, const char*, const SDL::Texture&,
		int scaleX=0, int scaleY=0,
		int offsetX = 0, int offsety = 0
	);
	
	void Startup(Game&) override;
	void Update(Game&) override;

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


