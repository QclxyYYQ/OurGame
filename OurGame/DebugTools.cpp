#include"DebugTools.h"
#include"DirectX.h"
#include"MapTool.h"
namespace DebugTools {
    int player1_x;
    int player1_y;
    string int2str(int int_temp) {
        stringstream stream;
        stream << int_temp;
        return stream.str();
    }
    void PrintMouseInfo() {
        static LPD3DXFONT font = MakeFont("宋体", 18);
        string text;
        text += "Total FPS：";
        text += int2str(Global::Debug::currentFPS);
        text += " Logical FPS：";
        text += int2str(Global::Window::targetFps);
        text += "\n";
        text += "鼠标 X：";
        text += int2str(Mouse_X());
        text += " Y: ";
        text += int2str(Mouse_Y());
        text += "\n";
        text += "玩家1 X:";
        text += int2str(player1_x);
        text += " Y: ";
        text += int2str(player1_y);
        FontPrint(font, 0, 0, text, D3DCOLOR_XRGB(255, 255, 255));

    }
    //绘制地图网格
    void PrintGrid()
    {
        using namespace Global::Game;
        int count = Global::Game::MapSize / UnitSize;

        POINT p;
        p.x = Global::Game::StartX;
        p.y = Global::Game::StartY;
        POINT p2;
        p2.x = Global::Game::StartX + Global::Game::MapSize;
        p2.y = Global::Game::StartY;

        //画行
        for (int i = 1; i < count; i++)
        {
            p.y = p2.y += UnitSize;
            Draw2DLine(p, p2, D3DCOLOR_XRGB(255, 179, 167));
        }

        p.x = Global::Game::StartX;
        p.y = Global::Game::StartY;
        p2.x = Global::Game::StartX;
        p2.y = Global::Game::StartY + Global::Game::MapSize;
        //画列
        for (int i = 1; i < count; i++)
        {
            p.x = p2.x += UnitSize;
            Draw2DLine(p, p2, D3DCOLOR_XRGB(255, 179, 167));
        }
        //Draw2DRect(p, p2, p3, p4, D3DCOLOR_XRGB(255, 255, 255));
    }
    void SetPlayer1Pos(int x, int y)
    {
        player1_x = x;
        player1_y = y;
    }
}