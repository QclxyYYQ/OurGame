#pragma once
#include<iostream>
using namespace std;
enum GAME_STATE
{
    //���κγ�������ʼ״̬��
    None = -1,
    //��ӭ����
    Home = 0,
    //��Ϸ����
    Playing = 1
};
namespace Global {
    namespace Window {
        const string GameTitle = "Our Game";
        const int ScreenWidth = 1024;
        const int ScreenHeight = 768;
        const bool FULLSCREEN = false;
    }
}
