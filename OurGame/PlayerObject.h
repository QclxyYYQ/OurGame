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
    bool CheckAcross(int x, int y);
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

    void SlowSpeed(int speed);
    void AddSpeed(int speed);
private:
    void Move();
    void Launch();
    
};

