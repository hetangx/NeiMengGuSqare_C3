#ifndef DEF_ELS_HEAD
#define DEF_ELS_DEAD

#include <Windows.h>
#include <time.h>

#define DEF_TIMER1 1234

void OnPaint(HDC hDC);//������Ϣ

void PaintSqare(HDC hMemDC);//��ʾ����

int CreateRandomSqare();//�����������

void CopySqareToBack();//���������������

void OnCreate();

//���»س���
void OnReturn(HWND hWnd);

//��������
void SqareDown();

//��ʱ����Ӧ����
void OnTimer(HWND hWnd);

//����ͣ�����һ��  0 - ����������  1 - �������� 
int CanSqareDown();

#endif // !DEF_ELS_HEAD