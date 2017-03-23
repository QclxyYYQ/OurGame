#include "TileObject.h"
#include"Resource.h"
bool TileObject::Init(ObjectType o, int x, int y)
{
    if (Resource::Textures::tileTextures == NULL)
        Resource::Textures::tileTextures = LoadTexture(Resource::Game::Tiles);
    type = o;
    location.x = x;
    location.y = y;
    return true;
}

void TileObject::Update()
{
}

void TileObject::Render()
{
    if (type != 0)
    {
        Sprite_Draw_Frame(Resource::Textures::tileTextures, Global::Game::StartX + location.x*Global::Game::UnitSize, Global::Game::StartY + location.y*Global::Game::UnitSize, type - 1, Global::Game::UnitSize, Global::Game::UnitSize, 9);
    }

}
