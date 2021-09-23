#pragma once

#include "Vector2.h"
#include "Graphics.h"

class GameObject {

private:
	int ID;
	Vector2 position;
	Graphics gfx;

public:
	virtual void Update();

    int GetId() const;
    void SetId(int id);

    const Vector2 &GetPosition() const;
    Vector2 GetOrigin() const;
    void SetPosition(const Vector2 &position);

    const Graphics &GetGfx() const;
    void SetGfx(const Graphics &gfx);

    bool CollideWith(const GameObject& other, bool filterSpaces = false);
};
