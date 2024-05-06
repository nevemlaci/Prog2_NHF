#include "Transform.hpp"

namespace SGL2 {

Vector2 Transform::Middle() const {
    return Vector2(this->position.x + (this->size.x / 2), this->position.y + (this->size.y / 2));
}

}
