#include "BulletObject.h"
#include"Resource.h"
#include"MapTool.h"
#include"DirectX.h"
bool BulletObject::Init(int x, int y, DIRECTION dir)
{
    if (Resource::Textures::bulletTexture == NULL)
        Resource::Textures::bulletTexture = LoadTexture(Resource::Game::Bullet);
    type = ObjectType::Bullet;
    location.x = x;
    location.y = y;
    BulletObject::dir = dir;
    sprite.x = MapTool::GetActualLocationX(location.x) + 16 - 4;
    sprite.y = MapTool::GetActualLocationY(location.y) + 16 - 4;

    speed = 2.0f;
    return true;
}
void BulletObject::Update()
{
    switch (dir)
    {
    case UP:
        if (sprite.y > Global::Game::StartY)
            sprite.y += speed;
        else
        {
            isDeleted = true;
        }
        break;
    case DOWN:
        if (sprite.y < Global::Game::StartY + Global::Game::MapSize - 8)
            sprite.y -= speed;
        else
        {
            isDeleted = true;
        } break;
    case LEFT:
        if (sprite.x > Global::Game::StartX)
            sprite.x -= speed;
        else
        {
            isDeleted = true;
        }break;
    case RIGHT:
        if (sprite.x < Global::Game::StartX + Global::Game::MapSize - 8)
            sprite.x += speed;
        else {
            isDeleted = true;
        }
        break;
    default:
        break;
    }
}

void BulletObject::Render()
{
    if (type != ObjectType::Null)
    {
        Sprite_Draw_Frame(Resource::Textures::bulletTexture,
            sprite.x,
            sprite.y,
            dir, 8, 8, 4);
    }

}
