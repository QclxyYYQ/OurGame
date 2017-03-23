#pragma once
#include "BaseObject.h"
#include"DirectX.h"
class BulletObject :
    public virtual BaseObject
{
public:
    bool Init(int x, int y, DIRECTION dir);
    void Update();
    void Render();
    int dir;
    POINT location;
    float speed;
    SPRITE sprite;
    bool isDeleted;
};

