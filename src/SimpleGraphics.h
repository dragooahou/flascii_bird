#pragma once

#include <vector>

#include "AsciiSprite.h"
#include "IGraphics.h"

class SimpleGraphics : public IGraphics {

private:
	std::vector<AsciiSprite*> sprites;
	float speed = 1;
	int currentFrame = 0;

public:

    SimpleGraphics() = default;
    SimpleGraphics(const std::vector<AsciiSprite*> &sprites, Layer layer);

    const std::vector<AsciiSprite*> &GetSprites() const;

    float GetSpeed() const;

    int GetCurrentFrameID() const;
    const AsciiSprite* GetCurrentFrame() override;



    void SetSpeed(float speed);
    void SetCurrentFrame(int currentFrame);


};


