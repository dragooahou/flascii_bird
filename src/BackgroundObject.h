#pragma once

#include "GameObject.h"


class BackgroundObject : public GameObject {

private:

	float depth;

public :

	BackgroundObject() = default;
	BackgroundObject(float depth, const Vector2 &position, GfxPtr gfx);

	void Update();
	float GetDepth();

};