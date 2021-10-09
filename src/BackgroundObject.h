#pragma once

#include "GameObject.h"


class BackgroundObject : public GameObject {

private:
	float depth;
	void SetDepth(float depth);


public :
	float GetDepth();

	BackgroundObject();
	BackgroundObject(float depth, const Vector2 &position, GfxPtr gfx);
	void Update();


};