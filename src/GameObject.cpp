#include "GameObject.h"

void GameObject::Update() {

}

int GameObject::GetId() const {
    return ID;
}

void GameObject::SetId(int id) {
    ID = id;
}

const Vector2 &GameObject::GetPosition() const {
    return position;
}

void GameObject::SetPosition(const Vector2 &position) {
    GameObject::position = position;
}

const Graphics &GameObject::GetGfx() const {
    return gfx;
}

void GameObject::SetGfx(const Graphics &gfx) {
    GameObject::gfx = gfx;
}

