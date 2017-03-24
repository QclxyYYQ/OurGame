#pragma once
#include"BaseObject.h"
namespace Map {
    void Init();
    void Render();
    void Update();
    //����һ���ӵ�
    void CreateBullet(int belongTo, int x, int y, DIRECTION Dir, float speed);
    BaseObject* GetMapObject(int x, int y);
    int GetBulletCount();
}