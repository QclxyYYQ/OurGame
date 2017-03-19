#include "HomeScene.h"
#include "Global.h"
#include "DirectX.h"
using namespace Global;
using namespace Global::Window;

bool HomeScene::Create_Background()
{
    //load background
    LPDIRECT3DSURFACE9 image = NULL;
    image = LoadSurface(Resource::Home::Backgroud);
    if (!image) return false;

    ////����2D�ı���background
    //HRESULT result = d3dDev->CreateOffscreenPlainSurface(
    //    ScreenWidth,
    //    ScreenHeight,
    //    D3DFMT_X8R8G8B8,
    //    D3DPOOL_DEFAULT,
    //    &background,
    //    NULL);
    //if (result != D3D_OK) return false;

    //���������StretchRect����������
    RECT source_rect = { 0, 0, ScreenWidth, ScreenHeight };

    d3dDev->StretchRect(
        image,
        &source_rect,
        background,
        &source_rect,
        D3DTEXF_NONE);

    //�ͷ�ͼ�����
    image->Release();
    return true;

}

void HomeScene::Draw_Background()
{
    RECT source_rect = {
        0,
        0,
        ScreenWidth,
        ScreenHeight
    };
    d3dDev->StretchRect(background, &source_rect, backBuffer, &source_rect, D3DTEXF_NONE);
}

bool HomeScene::Init()
{
    OutputDebugString("��ӭ������ʼ��ʼ��\n");
    if (!HomeScene::Create_Background())
    {
        ShowMessage("����ͼ����ʧ��");
    }

    return true;
}
void HomeScene::End()
{

}
void HomeScene::Update()
{
}
void HomeScene::Render()
{
    //HomeScene::Draw_Background();
    
}