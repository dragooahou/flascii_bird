#include "GameObject.h"

void GameObject::Update() {

}

GameObject::GameObject() : position(), gfx() {

}

GameObject::GameObject(Vector2 position, GfxPtr gfx) {
    SetPosition(position);
    SetGfx(gfx);
    SetRotation(0.f);
}


const Vector2 &GameObject::GetPosition() const {
    return position;
}

void GameObject::SetPosition(const Vector2 &position) {
    GameObject::position = position;
}

GameObject::GfxPtr GameObject::GetGfx() const {
    return gfx;
}

void GameObject::SetGfx(GfxPtr gfx) {
    GameObject::gfx = gfx;
}

bool GameObject::CollideWith(const GameObject& other) const {
    // Nothing
    const Colliders::ICollider* otherCollider = other.GetCollider();
    if(otherCollider == nullptr) {
        return false;
    }

    const Colliders::ICollider* thisCollider = GetCollider();
    if(thisCollider == nullptr) {
        return false;
    }

    return otherCollider->CollideWith(*thisCollider);
}

Vector2 GameObject::GetOrigin() const {
    return position + gfx->GetCurrentFrame()->GetCenterOffset();
}

float GameObject::GetRotation() const {
    return gfx->GetRotation();
}

void GameObject::SetRotation(float rotation) {
    gfx->SetRotation(rotation);
}

const Colliders::ICollider *GameObject::GetCollider() const {
    return nullptr;
}

