#include"MapTool.h"
#include"Global.h"
#include<math.h>
namespace MapTool {

    double round(double r)
    {
        return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
    }

    //将地图坐标X转换为屏幕坐标
    int GetActualLocationX(int x)
    {
        return Global::Game::StartX + x*Global::Game::UnitSize;

    }
    //将地图坐标Y转换为屏幕坐标
    int GetActualLocationY(int y)
    {
        return Global::Game::StartY + y*Global::Game::UnitSize;
    }
    //将屏幕坐标转为地图坐标，在两个格子之间时，进行四舍五入
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