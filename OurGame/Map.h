#pragma once
#include"BaseObject.h"
#include"TileObject.h"
namespace Map {
    extern TileObject *mapObjects[Global::Game::MapGridNum][Global::Game::MapGridNum];
    void Init();
    void Render();
    void Update();
    //创建一颗子弹
    void CreateBullet(int belongTo, int x, int y, DIRECTION Dir, float speed);
    //创建玩家
    void CreatePlayer(int id, int x, int y);
    TileObject* GetMapObject(int x, int y);
    int GetBulletCount();
}