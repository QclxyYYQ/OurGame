#include"MapTool.h"
#include"Global.h"
#include<math.h>
namespace MapTool {

    double round(double r)
    {
        return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
    }

    //����ͼ����Xת��Ϊ��Ļ����
    int GetActualLocationX(int x)
    {
        return Global::Game::StartX + x*Global::Game::UnitSize;

    }
    //����ͼ����Yת��Ϊ��Ļ����
    int GetActualLocationY(int y)
    {
        return Global::Game::StartY + y*Global::Game::UnitSize;
    }
    //����Ļ����תΪ��ͼ���꣬����������֮��ʱ��������������
    int GetMapLocationX(int x)
    {
        x -= Global::Game::StartX;
        if (x > 0)
        {
            
            return round(((float)x) / (float)Global::Game::UnitSize);
        }
        return 0;
    }

    int GetMapLocationY(int y)
    {
        y -= Global::Game::StartY;
        if (y > 0)
        {
            return round(((float)y) / (float)Global::Game::UnitSize);
        }
        return 0;
    }

}