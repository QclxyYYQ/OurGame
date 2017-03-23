#include"MapTool.h"
#include"Global.h"
namespace MapTool {
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
}