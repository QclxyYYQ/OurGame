#pragma once
#include<iostream>
#include<Windows.h>
#include"Resource.h"
#include"WinMain.h"
#include"DirectX.h"

using namespace std;
enum GAME_STATE
{
    //���κγ�������ʼ״̬��
    None = 0,
    //��ӭ����
    Home = 1,
    //��Ϸ����
    Playing = 2
};
namespace Global {
    namespace Window {
        const string GameTitle = "Our Game";
        const int ScreenWidth = 1024;
        const int ScreenHeight = 768;
        //���ڵ�����
        extern int x, y;
        extern bool EnableBackgroundRunning;
        extern bool isActity;
        //���������
        const float CursorSensitivity = 1.0f;
        const bool FullScreen = false;
        //ָ���߼�ˢ���ٶ�
        const float targetFps = 60.0f;
    }
    namespace Debug {
        //�Ƿ���ʾ������Ϣ
        const bool ShowDebugInfo = true;
        //��ǰ��֡��
        extern int currentFPS;
    }
}
