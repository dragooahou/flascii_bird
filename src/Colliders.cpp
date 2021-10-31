//
// Created by etien on 30/09/2021.
//

#include <stdexcept>
#include "Colliders.h"

bool Colliders::CollideImpl(const Rectangle &lhs, const Rectangle &rhs) {

    const float intersectionX1 = fmax(lhs.position.x, rhs.position.x);
    const float intersectionX2 = fmin(lhs.position.x + lhs.size.w, rhs.position.x + rhs.size.w);
    if (intersectionX2 < intersectionX1) {
        return false;
    }

    const float intersectionY1 = fmax(lhs.position.y, rhs.position.y);
    const float intersectionY2 = fmin(lhs.position.y + lhs.size.h, rhs.position.y + rhs.size.h);
    if (intersectionY2 < intersectionY1) {
        return false;
    }

    return true;

}

bool Colliders::CollideImpl(const Circle &lhs, const Circle &rhs) {
    return lhs.position.Distance(rhs.position) < lhs.radius + rhs.radius;
}

bool Colliders::CollideImpl(const Circle &lhs, const Rectangle &rhs) {
    throw std::runtime_error("not implemented");
}

bool Colliders::CollideImpl(const Compound &lhs, const ICollider &rhs) {

    for(auto& collider : lhs.colliders) {

        // Apply position of the parent to the child to put the coords of the child to world space
        collider->position += lhs.position;

        if(collider->CollideWith(rhs)) {

            // Don't forget to put coords of the child back to local space
            collider->position -= lhs.position;

            return true;
        }

        // Don't forget to put coords of the child back to local space
        collider->position -= lhs.position;

    }

    return false;
}

bool Colliders::Circle::CollideWith(const Colliders::Rectangle &other) const {
    return Collide(*this, other);
}

bool Colliders::Circle::CollideWith(const Colliders::Circle &other) const {
    return Collide(*this, other);
}

bool Colliders::Circle::CollideWith(const Colliders::ICollider &other) const {
    return other.CollideWith(*this);
}

bool Colliders::Circle::CollideWith(const Colliders::Compound &other) const {
    return Collide(*this, other);
}

bool Colliders::Circle::CollideWith(const Vector2 &point) const {
    return position.Distance(point) < radius;
}

bool Colliders::Rectangle::CollideWith(const Colliders::Rectangle &other) const {
    return Collide(*this, other);
}

bool Colliders::Rectangle::CollideWith(const Colliders::Circle &other) const {
    return Collide(*this, other);
}

bool Colliders::Rectangle::CollideWith(const Colliders::ICollider &other) const {
    return other.CollideWith(*this);
}

bool Colliders::Rectangle::CollideWith(const Colliders::Compound &other) const {
    return Collide(*this, other);
}

bool Colliders::Rectangle::CollideWith(const Vector2 &point) const {
    return point.x > position.x && point.x < position.x + size.x && point.y > position.y && point.y < position.y + size.y;
}

bool Colliders::Compound::CollideWith(const Colliders::ICollider &other) const {
    return other.CollideWith(*this);
}

bool Colliders::Compound::CollideWith(const Colliders::Rectangle &other) const {
    return Collide(*this, other);
}

bool Colliders::Compound::CollideWith(const Colliders::Circle &other) const {
    return Collide(*this, other);
}

bool Colliders::Compound::CollideWith(const Colliders::Compound &other) const {
    return Collide(*this, other);
}

bool Colliders::Compound::CollideWith(const Vector2 &point) const {

    for(const auto& collider : colliders) {

        // Apply position of the parent to the child to put the coords of the child to world space
        collider->position += position;

        if(collider->CollideWith(point)) {

            // Don't forget to put coords of the child back to local space
            collider->position -= position;

            return true;
        }

        // Don't forget to put coords of the child back to local space
        collider->position -= position;
    }

    return false;
}
