#pragma once

#include "Vector2.h"
#include "Graphics.h"

class GameObject {

private:
	Vector2 position;
	Graphics gfx;

public:
	virtual void Update();

    GameObject();
    GameObject(Vector2 position, Graphics gfx);

    const Vector2 &GetPosition() const;
    void SetPosition(const Vector2 &position);

    const Graphics &GetGfx() const;
    void SetGfx(const Graphics &gfx);
};
