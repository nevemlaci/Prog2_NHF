// GameObject.hpp

#ifndef __GameObject_H__
#define __GameObject_H__

#include <vector>
#include <memory>

#include "Component.hpp"

#ifndef CPORTA

#endif

namespace SGE2 {
class GameObject {
public:
	GameObject();
	virtual ~GameObject();

	/// @brief Called after the game initialization is finished
	virtual void Startup() = 0; 
	/// @brief Called every frame
	virtual void Update() = 0;

	template <class T, class... Args>
	Component& AddComponent(Args&&... args) {
		m_Components.push_back(T(std::forward<Args>(args)...));
		return (*m_Components.back());
	}

	template <class T>
	Component& GetComponent() {
		for (auto& component_ptr : m_Components) {
			Component* tryCast = dynamic_cast<T>(component_ptr.get());
			if (tryCast) {
				return (*tryCast);
			}
		}
		throw "Component& GetComponent()<T> : Component with type not found";
	}

	template <class T>
	Component& GetComponent(const char* id) {
		for (auto& component_ptr : m_Components) {
			Component* tryCast = dynamic_cast<T>(component_ptr.get());
			if (tryCast && (strcmp(id, component_ptr->m_Id) == 0)) {
				return (*tryCast);
			}
		}
		throw "Component& GetComponent()<T> : Component with type not found";
	}
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif

protected:
	std::vector< std::unique_ptr<Component> > m_Components;
	//Transform m_Transform;
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif
};
}
#endif


