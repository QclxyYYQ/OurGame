#include "GameScene.h"
#include"DirectX.h"
bool GameScene::Init()
{
    return true;
}

void GameScene::End()
{
}

void GameScene::Render()
{
    POINT p;
    p.y = p.x = 100;
    POINT p2;
    p2.x = p2.y = 200;
    Draw2DLine(p, p2, D3DCOLOR_XRGB(255, 255, 255));
    //Draw2DCircle(p, 100, D3DCOLOR_XRGB(255, 255, 255));
}

void GameScene::Update()
{
}
