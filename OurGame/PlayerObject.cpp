#include "PlayerObject.h"
#include"Resource.h"
#include"DirectX.h"
using namespace Resource;
bool PlayerObject::Init()
{
    texture = LoadTexture(Game::Player1);
    sprite.x = Global::Game::StartX;
    sprite.y = Global::Game::StartY;
    moveSpeed = 8;
    return true;
}

void PlayerObject::Update()
{
    if (Key_Down(DIK_DOWN))
    {
        if (sprite.y < Global::Game::StartY + Global::Game::MapSize - Global::Game::UnitSize)
        {
            sprite.y += moveSpeed;
        }
    }
    if (Key_Down(DIK_UP))
    {
        if (sprite.y > Global::Game::StartY)
        {
            sprite.y -= moveSpeed;
        }
    }
    if (Key_Down(DIK_LEFT))
    {
        if (sprite.x > Global::Game::StartX)
        {
            sprite.x -= moveSpeed;
        }
    }
    if (Key_Down(DIK_RIGHT))
    {
        if (sprite.x < Global::Game::StartX + Global::Game::MapSize - Global::Game::UnitSize)
        {
            sprite.x += moveSpeed;
        }
    }
    Sprite_Animate(sprite.frame, 0, 1, 1, sprite.starttime, 40);
}

void PlayerObject::Render()
{
    Sprite_Draw_Frame(texture, sprite.x, sprite.y, sprite.frame, Global::Game::UnitSize, Global::Game::UnitSize, 4);
}
