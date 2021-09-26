#pragma once

#include "Vector2.h"
#include "SimpleGraphics.h"

class GameObject {

public:
    using GfxPtr = std::shared_ptr<IGraphics>;


private:
	Vector2 position;
    GfxPtr gfx;

public:
	virtual void Update();

    GameObject();
    GameObject(Vector2 position, GfxPtr gfx);

    const Vector2 &GetPosition() const;
    Vector2 GetOrigin() const;
    void SetPosition(const Vector2 &position);

    float GetRotation() const;
    void SetRotation(float rotation);

    GfxPtr GetGfx() const;
    void SetGfx(GfxPtr gfx);

    bool CollideWith(const GameObject& other, bool filterSpaces = false);
};
