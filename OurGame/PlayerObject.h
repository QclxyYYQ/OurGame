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
    SPRITE sprite;
    //����
    DIRECTION direction;
    //���1�����2
    int which;
    //�ȼ�
    int level ;
    //�����ƶ�
    bool isMoving;
    void Move();
};

