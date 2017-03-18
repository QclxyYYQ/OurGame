// Beginning Game Programming
// Chapter 2 - Game Loop project

#include <windows.h>
#include <iostream>
#include <time.h>
#include"Global.h"
#include"GameMain.h"
using namespace std;

HWND window;
HDC device;
bool Gameover = false;

// Window callback function
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        Gameover = true;
        PostQuitMessage(0);
        break;
    case WM_PAINT:
        Game_Render(hWnd, device);
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

// MyRegiserClass function sets program window properties
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    //create the window class structure
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);

    //fill the struct with info
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = (WNDPROC)WinProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = Global::Window::GameTitle.c_str();
    wc.hIconSm = NULL;

    //set up the window with the class info
    return RegisterClassEx(&wc);
}

// Helper function to create the window and refresh it
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    //create a new window
    window = CreateWindow(
        Global::Window::GameTitle.c_str(),              //window class
        Global::Window::GameTitle.c_str(),              //title bar
        WS_OVERLAPPEDWINDOW,   //window style
        CW_USEDEFAULT,         //x position of window
        CW_USEDEFAULT,         //y position of window
        Global::Window::ScreenWidth,                   //width of the window
        Global::Window::ScreenHeight,                   //height of the window
        NULL,                  //parent window
        NULL,                  //menu
        hInstance,             //application instance
        NULL);                 //window parameters

                               //was there an error creating the window?
    if (window == 0) return 0;

    //display the window
    ShowWindow(window, nCmdShow);
    UpdateWindow(window);

    //get device context for drawing
    device = GetDC(window);

    return 1;
}

// Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg;

    //create window
    MyRegisterClass(hInstance);
    if (!InitInstance(hInstance, nCmdShow)) return -1;

    //initialize the game
    if (!Game_Init(window)) {
        ShowMessage("��Ϸ��ʼ��ʧ��");
        return -1;
    }

    while (!Gameover)
    {
        //process Windows events
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            DWORD timeInPerFrame = 1000.0f / Global::Window::constFps;    //����ÿ֡��Ƶ��
            DWORD timeBegin = GetTickCount();           //ѭ����ʼ��ʱ��  
            Game_Update(window);                        //directXѭ��
            Game_Render(window, device);                //directX��Ⱦ
            DWORD timePhase = GetTickCount() - timeBegin; //ѭ���ķѵ�ʱ��
            if (timePhase < timeInPerFrame)                //ѭ���ķѵ�ʱ��<ÿ֡��ʱ��
            {
                Sleep(DWORD(timeInPerFrame - timePhase)); //��ʣ���ʱ��ȴ�
            }
        }
    }

    //free game resources
    Game_Free(window, device);

    return msg.wParam;
}

//������Ϸ
void EndApplication()
{
    PostMessage(window, WM_DESTROY, 0, 0);
}
void ShowMessage(string text)
{
    MessageBox(window, text.c_str(), Global::Window::GameTitle.c_str(), MB_OK);
}
