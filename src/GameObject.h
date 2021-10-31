#pragma once

#include "Vector2.h"
#include "SimpleGraphics.h"
#include "Colliders.h"

#define SPEED 2.f

class GameObject {

public:
    using GfxPtr = std::shared_ptr<IGraphics>;


private:
	Vector2 position;
    GfxPtr gfx;

public:

	virtual void Update();

    GameObject() = default;
    GameObject(Vector2 position, GfxPtr gfx);

    const Vector2 &GetPosition() const;
    Vector2 GetOrigin() const;
    void SetPosition(const Vector2 &position);

    float GetRotation() const;
    void SetRotation(float rotation);

    GfxPtr GetGfx() const;
    void SetGfx(GfxPtr gfx);

    bool CollideWith(const GameObject& other) const;

    // Return null if no collider
    virtual const Colliders::ICollider* GetCollider() const;
};
