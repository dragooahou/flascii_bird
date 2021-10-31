#pragma once

#include "Scene.h"


class TitleScene : public Scene {

private :
    
    constexpr static int STAR_COUNT = 3;

    AsciiSprite starSprites[STAR_COUNT];
    AsciiSprite titleSprite;

public :

	TitleScene(int sceneID);
	void Update() override;

};