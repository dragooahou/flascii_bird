#include "GameObject.h"

void GameObject::Update() {

}

GameObject::GameObject() {

}

GameObject::GameObject(Vector2 position, Graphics gfx) {
    SetPosition(position);
    SetGfx(gfx);
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

