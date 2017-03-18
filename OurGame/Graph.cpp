#include"Graph.h"
#include<Windows.h>
#include"Resource.h"
namespace Graph {
    // Loads and draws a bitmap from a file and then frees the memory
    // (not really suitable for a game loop but it's self contained)
    void DrawBitmap(HDC device, const char *filename, int x, int y)
    {
        //load the bitmap image
        HBITMAP image = (HBITMAP)LoadImage(0, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        //read the bitmap's properties
        BITMAP bm;
        GetObject(image, sizeof(BITMAP), &bm);

        //create a device context for the bitmap
        HDC hdcImage = CreateCompatibleDC(device);
        SelectObject(hdcImage, image);

        //draw the bitmap to the window (bit block transfer)
        BitBlt(
            device,                  //destination device context
            x, y,                    //x,y position
            bm.bmWidth, bm.bmHeight, //size of source bitmap
            hdcImage,                //source device context
            0, 0,                    //upper-left source position
            SRCCOPY);                //blit method

                                     //delete the device context and bitmap
        DeleteDC(hdcImage);
        DeleteObject((HBITMAP)image);
    }
    float GetFPS()
    {
        static float  fps = 0;
        static int    frameCount = 0;
        static float  currentTime = 0.0f;//��ǰʱ��
        static float  lastTime = 0.0f;//����ʱ��

        frameCount++;//ÿ����һ��Get_FPS()������֡��+1
        currentTime = timeGetTime()*0.001f;//��ȡϵͳʱ��,��ת������Ϊ��λ
                                           //������һ�룬�ͽ���һ��FPS�ļ���ͳ���ʱ��ĸ��£�����֡��ֵ����
        if (currentTime - lastTime > 1.0f) //��ʱ�������1����
        {
            fps = (float)frameCount / (currentTime - lastTime);//������1���ӵ�FPSֵ
            lastTime = currentTime; //����ǰʱ��currentTime��Ϊ��һ��Ļ�׼ʱ��
            frameCount = 0;//������֡��frameCountֵ����
        }
        return fps;
    }
}