#ifndef DEF_ELS_HEAD
#define DEF_ELS_DEAD

#include <Windows.h>
#include <time.h>

void OnPaint(HDC hDC);//������Ϣ

void PaintSqare(HDC hMemDC);//��ʾ����

int CreateRandomSqare();//�����������

void CopySqareToBack();//���������������

void OnCreate();

#endif // !DEF_ELS_HEAD