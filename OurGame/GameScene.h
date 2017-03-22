#pragma once
#include "Scene.h"
#include"PlayerObject.h"
class GameScene : public virtual Scene
{
public:
    bool Init();
    void End();
    void Render();
    void Update();
private:
    void PrintBorder();
    PlayerObject *player1;
};

