// RendererComponent.hpp

#ifndef __RendererComponent_H__
#define __RendererComponent_H__

#ifndef CPORTA
#include "Component.hpp"
#include <iostream>

#include "cpp_SDL_include.hpp"


#include "memtrace.h"

namespace SGL2 {
class RendererComponent final : public Component {
public:
	RendererComponent(
		GameObject& root, const std::string& id,
		const std::string& asset_name,
		double scaleX = 1, double scaleY = 1,
		double offsetX = 0, double offsety = 0
	);

	void Startup(Game_t& game) override;
	void Update(Game_t& game) override;

private:
	double m_OffsetX;
	double m_OffsetY;
	double m_ScaleX;
	double m_ScaleY;
	const SDL::Texture& m_Texture;

};
}
#endif
#endif


