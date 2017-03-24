#pragma once
#include"BaseObject.h"
#include"TileObject.h"
namespace Map {
    void Init();
    void Render();
    void Update();
    //����һ���ӵ�
    void CreateBullet(int belongTo, int x, int y, DIRECTION Dir, float speed);
    //�������
    void CreatePlayer(int id, int x, int y);
    TileObject* GetMapObject(int x, int y);
    int GetBulletCount();
}