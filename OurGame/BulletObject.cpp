#include "BulletObject.h"
#include"Resource.h"
#include"MapTool.h"
#include"DirectX.h"
#include"Map.h"
bool BulletObject::Init(int x, int y, DIRECTION dir)
{
    if (Resource::Textures::bulletTexture == NULL)
        Resource::Textures::bulletTexture = LoadTexture(Resource::Game::Bullet);
    type = ObjectType::Bullet;
    BulletObject::dir = dir;
    //加上从坦克左上角顶点到坦克炮筒的坐标偏移
    sprite.x = x + 10;
    sprite.y = y + 10;

    return true;
}
void BulletObject::Update()
{
    switch (dir)
    {
    case UP:
        if (sprite.y > Global::Game::StartY)
            sprite.y -= speed;
        else
        {
            isDeleted = true;
        }
        break;
    case DOWN:
        if (sprite.y < Global::Game::StartY + Global::Game::MapSize - 8)
            sprite.y += speed;
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
