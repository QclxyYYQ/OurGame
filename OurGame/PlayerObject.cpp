#include "PlayerObject.h"
#include"Resource.h"
#include"DirectX.h"
using namespace Resource;
bool PlayerObject::Init(int which)
{
    PlayerObject::which = which;
    if (which == 1)
    {
        Resource::Textures::playerTexture1 = LoadTexture(Game::Player1);
    }
    else {
        Resource::Textures::playerTexture2 = LoadTexture(Game::Player2);
    }
    sprite.x = Global::Game::StartX;
    sprite.y = Global::Game::StartY;
    type = ObjectType::Player;
    moveSpeed = 4;
    level = 3;
    return true;
}

void PlayerObject::Update()
{
    Move();
    if (isMoving)
        Sprite_Animate(sprite.frame, direction * 8 + (level - 1) * 2, direction * 8 + (level - 1) * 2 + 1, 1, sprite.starttime, 20);
}

void PlayerObject::Render()
{
    Sprite_Draw_Frame(which == 1 ? Resource::Textures::playerTexture1 : Resource::Textures::playerTexture2, sprite.x, sprite.y, sprite.frame, 28, 28, 8);
}

void PlayerObject::Move()
{
    if (PlayerObject::which == 1)
    {
        if (Key_Down(DIK_S))
        {
            direction = DIRECTION::DOWN;
            isMoving = true;
            if (sprite.y < Global::Game::StartY + Global::Game::MapSize - Global::Game::UnitSize)
            {
                sprite.y += moveSpeed;
            }
        }
        else if (Key_Down(DIK_W))
        {
            direction = DIRECTION::UP;
            isMoving = true;

            if (sprite.y > Global::Game::StartY)
            {
                sprite.y -= moveSpeed;
            }
        }
        else if (Key_Down(DIK_A))
        {
            direction = DIRECTION::LEFT;
            isMoving = true;

            if (sprite.x > Global::Game::StartX)
            {
                sprite.x -= moveSpeed;
            }
        }
        else if (Key_Down(DIK_D))
        {
            direction = DIRECTION::RIGHT;
            isMoving = true;

            if (sprite.x < Global::Game::StartX + Global::Game::MapSize - Global::Game::UnitSize)
            {
                sprite.x += moveSpeed;
            }
        }
        else {
            isMoving = false;
        }
    }
    else {
        if (Key_Down(DIK_DOWN))
        {
            direction = DIRECTION::DOWN;
            isMoving = true;

            if (sprite.y < Global::Game::StartY + Global::Game::MapSize - Global::Game::UnitSize)
            {
                sprite.y += moveSpeed;
            }
        }
        else if (Key_Down(DIK_UP))
        {
            direction = DIRECTION::UP;
            isMoving = true;

            if (sprite.y > Global::Game::StartY)
            {
                sprite.y -= moveSpeed;
            }
        }
        else if (Key_Down(DIK_LEFT))
        {
            direction = DIRECTION::LEFT;
            isMoving = true;

            if (sprite.x > Global::Game::StartX)
            {
                sprite.x -= moveSpeed;
            }
        }
        else if (Key_Down(DIK_RIGHT))
        {
            direction = DIRECTION::RIGHT;
            isMoving = true;

            if (sprite.x < Global::Game::StartX + Global::Game::MapSize - Global::Game::UnitSize)
            {
                sprite.x += moveSpeed;
            }
        }
        else {
            isMoving = false;
        }
    }
}
