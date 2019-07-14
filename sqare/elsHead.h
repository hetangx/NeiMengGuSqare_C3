#ifndef DEF_ELS_HEAD
#define DEF_ELS_DEAD

#include <Windows.h>
#include <time.h>

void OnPaint(HDC hDC);//处理消息

void PaintSqare(HDC hMemDC);//显示方块

int CreateRandomSqare();//创建随机方块

void CopySqareToBack();//随机方块贴进背景

void OnCreate();

#endif // !DEF_ELS_HEAD