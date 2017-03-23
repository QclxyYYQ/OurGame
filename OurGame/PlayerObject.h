#pragma once
#include "BaseObject.h"
#include"DirectX.h"
class PlayerObject :
    public virtual BaseObject
{
public:
    bool Init(int which);
    void Update();
    void Render();
    int moveSpeed;
    enum DIRECTION
    {
        UP = 0,
        RIGHT = 1,
        DOWN = 2,
        LEFT = 3,
    };
private:
    SPRITE sprite;
    LPDIRECT3DTEXTURE9 texture;
    //���1�����2
    int which;
    //����
    DIRECTION direction;
    //�ȼ�
    int level ;
    void Move();
};

