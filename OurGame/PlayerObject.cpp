#include "PlayerObject.h"
#include"Resource.h"
#include"DirectX.h"
#include"Map.h"
#include"MapTool.h"
#include"TileObject.h"
using namespace Resource;
bool PlayerObject::Init(int which)
{
    PlayerObject::id = which;
    if (which == 1)
    {
        Resource::Textures::playerTexture1 = LoadTexture(Game::Player1);
    }
    else {
        Resource::Textures::playerTexture2 = LoadTexture(Game::Player2);
    }
    sprite.x = Global::Game::StartX;
    sprite.y = Global::Game::StartY;
    sprite.width = sprite.height = 28;
    type = ObjectType::Player;
    moveSpeed = 8;
    level = 1;
    return true;
}

void PlayerObject::Update()
{
    Move();
    if (isMoving)
        Sprite_Animate(sprite.frame, direction * 8 + (level - 1) * 2, direction * 8 + (level - 1) * 2 + 1, 1, sprite.starttime, 20);
    Launch();
}

void PlayerObject::Render()
{
    Sprite_Draw_Frame(id == 1 ? Resource::Textures::playerTexture1 : Resource::Textures::playerTexture2, sprite.x, sprite.y, sprite.frame, sprite.width, sprite.height, 8);
}
bool PlayerObject::CheckAcross(int x, int y)
{
    /* int xx, yy;
     xx = MapTool::GetMapLocationX(x);
     yy = MapTool::GetMapLocationY(y);
    */
    SPRITE s;
    s.x = x;
    s.y = y;
    s.width = sprite.width;
    s.height = sprite.height;
    for (int i = 0; i < Global::Game::MapGridNum; i++)
    {
        for (int k = 0; k < Global::Game::MapGridNum; k++)
        {
            if (Map::mapObjects[i][k] != NULL)
            {
                switch (Map::mapObjects[i][k]->type)
                {
                case Brick:
                case Marble:
                case DeepWater:
                    if (Collision(Map::mapObjects[i][k]->sprite, s))
                    {
                        return false;
                    }
                default:
                    break;
                }
            }
        }
    }

    return true;
}
void PlayerObject::Move()
{
    if (PlayerObject::id == 1)
    {
        if (Key_Down(DIK_S))
        {
            direction = DIRECTION::DOWN;
            isMoving = true;

            if (sprite.y < Global::Game::StartY + Global::Game::MapSize - Global::Game::UnitSize)
            {
                if (!CheckAcross(sprite.x, sprite.y + moveSpeed))
                    return;
                sprite.y += moveSpeed;
            }
        }
        else if (Key_Down(DIK_W))
        {
            direction = DIRECTION::UP;
            isMoving = true;

            if (sprite.y > Global::Game::StartY)
            {
                if (!CheckAcross(sprite.x, sprite.y - moveSpeed))
                    return;
                sprite.y -= moveSpeed;
            }
        }
        else if (Key_Down(DIK_A))
        {
            direction = DIRECTION::LEFT;
            isMoving = true;

            if (sprite.x > Global::Game::StartX)
            {
                if (!CheckAcross(sprite.x - moveSpeed, sprite.y))
                    return;
                sprite.x -= moveSpeed;
            }
        }
        else if (Key_Down(DIK_D))
        {
            direction = DIRECTION::RIGHT;
            isMoving = true;

            if (sprite.x < Global::Game::StartX + Global::Game::MapSize - Global::Game::UnitSize)
            {
                if (!CheckAcross(sprite.x + moveSpeed, sprite.y))
                    return;
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

void PlayerObject::Launch()
{
    if (id == 1)
    {
        if (Key_Up(DIK_SPACE))
        {
            Map::CreateBullet(id, sprite.x, sprite.y, direction, 6);
        }
    }
    else {
        if (Key_Up(DIK_NUMPAD0))
        {
            Map::CreateBullet(id, sprite.x, sprite.y, direction, 6);
        }
    }

}
