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
    //方向
    DIRECTION direction;
    //玩家1或玩家2
    int which;
    //等级
    int level ;
    //正在移动
    bool isMoving;
    void Move();
};

