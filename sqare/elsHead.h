#ifndef DEF_ELS_HEAD
#define DEF_ELS_DEAD

#include <Windows.h>
#include <time.h>

#define DEF_TIMER1 1234

void OnPaint(HDC hDC);//������Ϣ

void PaintSqare(HDC hMemDC);//��ʾ����
void PaintSqare2(HDC hMemDC);

int CreateRandomSqare();//�����������

void CopySqareToBack();//���������������

void OnCreate();

//�����ƶ�
void SqareDown();//���齵��
void SqareLeft();//��������

//��Ӧ����
void OnReturn(HWND hWnd);//���»س���
void OnTimer(HWND hWnd);
void OnLeft(HWND hWnd);

//����ͣ�����һ��  0 - ����������  1 - �������� 
int CanSqareDown();
int CanSqareDown2();
int CanSqareLeft();
int CanSqareLeft2();

//��1���2
void Change1to2();

#endif // !DEF_ELS_HEAD