// UIRendererComponent.hpp

#ifndef __UIRendererComponent_H__
#define __UIRendererComponent_H__

#ifndef CPORTA
#include "Component.hpp"
#include <iostream>

#include "cpp_SDL_include.hpp"


#include "memtrace.h"

namespace SGL2 {
	/// @brief renders a texture on the screen with an absolute position. For scene rendering, see RendererComponent
	class UIRendererComponent final : public Component {
	public:
		/// @brief 
		/// @param root root game object(gets passed automatically by GameObject::AddComponent()
		/// @param id 
		/// @param asset_name the name of the texture asset to be rendered by this component
		/// @param scaleX scaling relative to the root's width
		/// @param scaleY scaling relative to the root's height
		/// @param offsetX offset from the root's X position
		/// @param offsety offset from the root's X position
		UIRendererComponent(
			GameObject& root, const std::string& id,
			const std::string& asset_name,
			int scaleX = 1, int scaleY = 1,
			int offsetX = 0, int offsety = 0
		);

		void Startup(Game_t& game) override;
		void Update(Game_t& game) override;

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


