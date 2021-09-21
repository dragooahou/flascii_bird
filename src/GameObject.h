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


};
