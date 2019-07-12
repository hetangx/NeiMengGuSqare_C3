#include <Windows.h>
#include "resource.h"
LRESULT CALLBACK PEluoSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);

//_In_ _In_opt_ is SAL, search MSDN Docs
//句柄：一个数, 窗口的唯一标识,
int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	//初始化窗口类
	WNDCLASSEX wc;   //WNDCLASS的拓展
	HWND hWnd;
	MSG mSg;

	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	//wc.hCursor = LoadCursor(NULL, IDC_ARROW); //加载系统光标，第一个参数必须为空
	wc.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_NODROP));//用户自己定义的指针图标，要先添加资源，然后在首行后添加 #include "resource.h"
	wc.hIcon = LoadIcon(hInstance, IDI_SELFTEST);  //TODO, 测试
	wc.hIconSm = LoadIcon(NULL,IDI_QUESTION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = PEluoSi;//回调函数地址
	wc.lpszClassName = "els";//窗口类名字，名字不要重复，给操作系统看的
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	
	//一共有12个成员，不多不少

	//注册窗口对象
	//ATOM //unsigned short 
	if (0 == RegisterClassEx(&wc))
	{
		//出错  getlasterror
		int a = GetLastError(); //函数
		return 0;
	}
	//创建窗口
	hWnd=CreateWindowEx(WS_EX_TOPMOST,"els","内蒙古方块",WS_OVERLAPPEDWINDOW,100,100,500,500,NULL,NULL,hInstance,NULL);
	if(NULL==hWnd)  //窗口句柄   123   窗口的唯一标识
	{
		return 0;
	}

	//显示窗口
	ShowWindow(hWnd, nShowCmd );/*也可以写  SW_SHOWNORMAL */
	//隐藏显示返回0   正常显示返回非0

	//消息循环
	while(GetMessage(&mSg, NULL, 0, 0))
	{
		//
		TranslateMessage(&mSg);//翻译消息
		//
		DispatchMessage(&mSg);//分发消息：  标准消息  命令消息 通知消息  自定义消息
	}	

	return 0;
}


LRESULT CALLBACK PEluoSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	switch (nMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0); //WM_CLOSE, WM_DESTROY, WM_QUIT
		break;
	}

	return DefWindowProc(hWnd, nMsg, wParam, lParam);//
}