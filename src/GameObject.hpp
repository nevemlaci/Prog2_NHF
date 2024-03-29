// GameObject.hpp

#ifndef __GameObject_H__
#define __GameObject_H__

#include <vector>
#include <memory>

#include "Component.hpp"
#include "Transform.hpp"

#ifndef CPORTA

#endif

namespace SGE2 {
class GameObject {
public:
	GameObject(const Vector2&, const Vector2&, float rot);
	virtual ~GameObject();

	/// @brief Called after the game initialization is finished
	virtual void Startup() = 0; 
	/// @brief Called every frame
	virtual void Update() = 0;

	/// @brief Constructs a new component and adds it to the GameObject
	/// @tparam T typename of component subclass to be added
	/// @tparam ...Args shouldn't be passed explicitly
	/// @param ...args parameters of the constructor of T(except the pointer to this game object)
	/// @return a reference to the newly added Component
	template <class T, class... Args>
	Component& AddComponent(Args&&... args) {
		m_Components.push_back(T(this, std::forward<Args>(args)...));
		return (*m_Components.back());
	}

	/// @brief Get the first component of T type of the GameObject
	/// @tparam T typename of component subclass
	/// @return the first T type component of the GameObject
	/// @throw "Component& GetComponent() : Component with type not found" | if a component with type T was not found.
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

	/// @brief Get the first component of T type of the GameObject with given id
	/// @tparam T typename of component subclass
	/// @param id
	/// @return the first T type component of the GameObject
	/// @throw "Component& GetComponent() : Component with type not found" | if a component with type T and with given id was not found.
	template <class T>
	Component& GetComponent(const char* id) {
		for (auto& component_ptr : m_Components) {
			Component* tryCast = dynamic_cast<T>(component_ptr.get());
			if (tryCast && (strcmp(id, component_ptr->GetId()) == 0)) {
				return (*tryCast);
			}
		}
		throw "Component& GetComponent()<T> : Component with type and id not found";
	}

	/// @brief Get the first component of the GameObject with given id
	/// @param id 
	/// @return the first component with given id of the GameObject
	Component& GetComponent(const char* id) {
		for (auto& component_ptr : m_Components) {
			
			if (strcmp(id, component_ptr->GetId()) == 0) {
				return (*component_ptr);
			}
		}
		throw "Component& GetComponent()<T> : Component with type not found";
	}

	Transform m_Transform;
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif

protected:
	std::vector< std::unique_ptr<Component> > m_Components;
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif
};
}
#endif


