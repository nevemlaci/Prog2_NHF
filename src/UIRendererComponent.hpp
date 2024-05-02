// UIRendererComponent.hpp

#ifndef __UIRendererComponent_H__
#define __UIRendererComponent_H__

#ifndef CPORTA
#include "Component.hpp"
#include <iostream>

#include "cpp_SDL_include.hpp"


#include "memtrace.h"

namespace SGL2 {
	class UIRendererComponent final : public Component {
	public:
		UIRendererComponent(
			GameObject& root, const std::string& id,
			const std::string& asset_name,
			int scaleX = 1, int scaleY = 1,
			int offsetX = 0, int offsety = 0
		);

		void Startup(Game& game) override;
		void Update(Game& game) override;

	private:
		int m_OffsetX;
		int m_OffsetY;
		int m_ScaleX;
		int m_ScaleY;
		const SDL::Texture& m_Texture;

	};
}
#endif
#endif


