#pragma once
#include "BaseObject.h"
#include"DirectX.h"
class PlayerObject :
    public virtual BaseObject
{
public:
    bool Init();
    void Update();
    void Render();
    int moveSpeed;
private:
    SPRITE sprite;
    LPDIRECT3DTEXTURE9 texture;

};

