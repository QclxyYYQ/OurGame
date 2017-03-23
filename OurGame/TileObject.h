#pragma once
#include "BaseObject.h"
#include"DirectX.h"
class TileObject :
    public virtual BaseObject
{
public:
    bool Init(ObjectType o, int x, int y);
    void Update();
    void Render();
    POINT location;
};

