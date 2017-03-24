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
    //����
    DIRECTION direction;
    //���1�����2
    int id;
    //�ȼ�
    int level ;
    //�����ƶ�
    bool isMoving;
private:
    void Move();
    void Launch();
    
};

