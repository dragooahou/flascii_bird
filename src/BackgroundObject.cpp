#include "BackgroundObject.h"
#include "GameObject.h"

float BackgroundObject::GetDepth()
{
	return depth;
}

void BackgroundObject::SetDepth(float depth)
{
	this->depth = depth;
}

BackgroundObject::BackgroundObject()
{
}

BackgroundObject::BackgroundObject(float depth, const Vector2& position, GfxPtr gfx)
{
	SetPosition(position);
	SetGfx(gfx);
	SetDepth(depth);
}


void BackgroundObject::Update()
{

	if (GetPosition().x <= -20) {
		SetPosition({ 250 + (rand() / (float)RAND_MAX) * 60, (rand() / (float)RAND_MAX) * 66 });
	}
	SetPosition({ GetPosition().x -(SPEED / (depth+2)), GetPosition().y });
}


