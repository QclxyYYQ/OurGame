#include"DebugTools.h"
#include"DirectX.h"
#include"Map.h"
namespace DebugTools {
    int player1_x;
    int player1_y;
    string int2str(int int_temp) {
        stringstream stream;
        stream << int_temp;
        return stream.str();
    }
    void PrintMouseInfo() {
        static LPD3DXFONT font = MakeFont("����", 18);
        string text;
        text += "Total FPS��";
        text += int2str(Global::Debug::currentFPS);
        text += " Logical FPS��";
        text += int2str(Global::Window::targetFps);
        text += "\n";
        text += "��� X��";
        text += int2str(Mouse_X());
        text += " Y: ";
        text += int2str(Mouse_Y());
        text += "\n";
        text += "���1 X:";
        text += int2str(player1_x);
        text += " Y: ";
        text += int2str(player1_y);
        text += "\n�ڵ�������";
        text += int2str(Map::GetBulletCount());

        FontPrint(font, 0, 0, text, D3DCOLOR_XRGB(255, 255, 255));

    }
    void PrintPlayerGrid(int x, int y)
    {
        POINT p1;
        p1.x = x;
        p1.y = y;
        POINT p2;
        p2.x = x + Global::Game::UnitSize;
        p2.y = y;
        POINT p3;
        p3.x = x;
        p3.y = y + +Global::Game::UnitSize;
        POINT p4;
        p4.x = x + Global::Game::UnitSize;;
        p4.y = y + Global::Game::UnitSize;
        Draw2DRect(p1, p2, p3, p4, D3DCOLOR_XRGB(128, 128, 128));
    }
    //���Ƶ�ͼ����
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

        //����
        for (int i = 1; i < count; i++)
        {
            p.y = p2.y += UnitSize;
            Draw2DLine(p, p2, D3DCOLOR_XRGB(255, 179, 167));
        }

        p.x = Global::Game::StartX;
        p.y = Global::Game::StartY;
        p2.x = Global::Game::StartX;
        p2.y = Global::Game::StartY + Global::Game::MapSize;
        //����
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