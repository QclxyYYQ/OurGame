#include"MapTool.h"
#include"Global.h"
namespace MapTool {
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
}