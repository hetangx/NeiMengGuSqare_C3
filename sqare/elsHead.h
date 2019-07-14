#ifndef DEF_ELS_HEAD
#define DEF_ELS_DEAD

#include <Windows.h>
#include <time.h>

#define DEF_TIMER1 1234

void OnPaint(HDC hDC);//处理消息

void PaintSqare(HDC hMemDC);//显示方块

int CreateRandomSqare();//创建随机方块

void CopySqareToBack();//随机方块贴进背景

void OnCreate();

//按下回车键
void OnReturn(HWND hWnd);

//方块下落
void SqareDown();

//定时器响应函数
void OnTimer(HWND hWnd);

//方块停在最后一行  0 - 不可以下落  1 - 可以下落 
int CanSqareDown();

#endif // !DEF_ELS_HEAD