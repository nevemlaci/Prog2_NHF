// GameObject.hpp

#ifndef __GameObject_H__
#define __GameObject_H__

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <functional>

#include "Component.hpp"
#include "Transform.hpp"

#ifndef CPORTA

#endif

namespace SGE2 {
class GameObject {
	friend class Game;
public:
	/// @brief Constructor
	/// @param position Vector2
	/// @param size Vector2
	/// @param rot rotation
	GameObject(
		Game& root_game, 
		const std::string& id, 
		const Vector2& position, 
		const Vector2& size, 
		float rot);

	virtual ~GameObject() {}

	/// @brief Constructs a new component and adds it to the GameObject
	/// @tparam T typename of component subclass to be added
	/// @tparam ...Args shouldn't be passed explicitly
	/// @param ...args parameters of the constructor of T(except the pointer to this game object)
	/// @return a reference to the newly added Component
	template <class T, class... Args>
	Component& AddComponent(Args&&... args) {
		m_Components.push_back(std::make_unique<T>((*this), std::forward<Args>(args)...));
		m_Components.back()->Startup(this->m_RootGameRef);
		return (*m_Components.back());
	}

	/// @brief Get the component of a given type
	/// @tparam T type of the component
	/// @return the first component of type T in the Component vecto
	/// @throw std::runtime_error : "GetComponent(): Component with type not found." | If a component with the given type was not found.
	template <class T>
	T& GetComponent() {
		for (auto& component_ptr : m_Components) {
			Component* tryCast = dynamic_cast<T*>(component_ptr.get());
			if (tryCast) {
				return dynamic_cast<T&>(*tryCast);
			}
		}
		throw std::runtime_error(std::string("GetComponent(): Component with type not found."));
	}

	/// @brief Get the first component of T type of the GameObject with a specific id
	/// @tparam T typename of component subclass
	/// @param id
	/// @return the first T type component of the GameObject
	/// @throw "Component& GetComponent() : Component with type not found" | if a component with type T and with given id was not found.
	template <class T>
	T& GetComponent(const std::string& id) {
		for (auto& component_ptr : m_Components) {
			Component* tryCast = dynamic_cast<T*>(component_ptr.get());
			if (tryCast && (id == component_ptr->GetId())) {
				return dynamic_cast<T&>(*tryCast);
			}
		}
		
		throw std::runtime_error(std::string("GetComponent(): Component with type and id not found."));
	}

	const std::string& GetId() { return m_Id; }

	Transform transform;
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif

protected:
	std::string m_Id;
	Game& m_RootGameRef;
	std::vector< std::unique_ptr<Component> > m_Components;
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif
};
}
#endif


