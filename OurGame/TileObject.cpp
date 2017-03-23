#include "TileObject.h"
#include"Resource.h"
#include"MapTool.h"
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
        Sprite_Draw_Frame(Resource::Textures::tileTextures, MapTool::GetActualLocationX(location.x), MapTool::GetActualLocationY(location.y), type - 1, Global::Game::UnitSize, Global::Game::UnitSize, 9);
    }

}
