#pragma once
#include "Scene.h"
class GameScene : public virtual Scene
{
public:
    bool Init();
    void End();
    void Render();
    void Update();
};

