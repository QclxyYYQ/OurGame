#pragma once
#include"BaseObject.h"
#include"TileObject.h"
namespace Map {
    extern TileObject *mapObjects[Global::Game::MapGridNum][Global::Game::MapGridNum];
    void Init();
    void Render();
    void Update();
    //����һ���ӵ�
    void CreateBullet(int belongTo, int x, int y, DIRECTION Dir, float speed);
    //�������
    void CreatePlayer(int id, int x, int y);
    TileObject* GetMapObject(int x, int y);
    int GetBulletCount();
    int GetNearTile(DIRECTION dir, int x, int y, TileObject** t);
}