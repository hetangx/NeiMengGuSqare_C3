#ifndef DEF_ELS_HEAD
#define DEF_ELS_DEAD

#include <Windows.h>
#include <time.h>

#define DEF_TIMER1 1234

void OnPaint(HDC hDC);//处理消息

void PaintSqare(HDC hMemDC);//显示方块
void PaintSqare2(HDC hMemDC);

int CreateRandomSqare();//创建随机方块

void CopySqareToBack();//随机方块贴进背景

void OnCreate();

//方块移动
void SqareDown();//方块降落
void SqareLeft();//方块左移

//响应函数
void OnReturn(HWND hWnd);//按下回车键
void OnTimer(HWND hWnd);
void OnLeft(HWND hWnd);

//方块停在最后一行  0 - 不可以下落  1 - 可以下落 
int CanSqareDown();
int CanSqareDown2();
int CanSqareLeft();
int CanSqareLeft2();

//把1变成2
void Change1to2();

#endif // !DEF_ELS_HEAD