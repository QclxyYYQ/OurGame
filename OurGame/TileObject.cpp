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
    sprite.x = MapTool::GetActualLocationX(x);
    sprite.y = MapTool::GetActualLocationY(y);
    sprite.width = sprite.height = Global::Game::UnitSize;
    return true;
}

void TileObject::Update()
{
}

void TileObject::Render()
{
    if (type != ObjectType::Null)
    {
        Sprite_Draw_Frame(Resource::Textures::tileTextures, sprite.x,sprite.y, type - 1, sprite.width, sprite.height, 9);
    }

}
