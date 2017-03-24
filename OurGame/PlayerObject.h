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

    SPRITE sprite;
    //方向
    DIRECTION direction;
    //玩家1或玩家2
    int id;
    //等级
    int level ;
    //正在移动
    bool isMoving;
private:
    void Move();
    void Launch();
    
};

