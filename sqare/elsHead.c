#include "elsHead.h"

//背景数组,使用char节省空间
char g_arrBackGround[20][10] = { 0 };//20行10列，i行j列
char g_arrSqare[2][4] = { 0 };


void OnPaint(HDC hDC)
{
	//创建兼容性DC
	HDC hMemDC = CreateCompatibleDC(hDC);
	//创建一张纸
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDC, 500, 600);
	//关联编号和纸
	SelectObject(hMemDC, hBitmapBack);

	PaintSqare(hMemDC);


	//内存DC传递至窗口DC
	BitBlt(hDC, 0, 0, 300, 600, hMemDC, 0, 0, SRCCOPY);

	//释放
	DeleteObject(hBitmapBack);
	DeleteDC(hMemDC);
}

void PaintSqare(HDC hMemDC)
{
	//画大方块
	Rectangle(hMemDC, 0, 0, 300, 600);

	/*
	//测试代码，指定某元素为1
	g_arrBackGround[2][4] = 1;
	g_arrBackGround[3][3] = 1;
	g_arrBackGround[3][4] = 1;
	g_arrBackGround[3][5] = 1;
	*/
	
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (g_arrBackGround[i][j] == 1)
			{
				//画小方块
				Rectangle(hMemDC, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
			}
		}
	}
}

int CreateRandomSqare()
{
	int nIndex = rand()%7;
	switch (nIndex)
	{
	case 0:
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0,		//	|■■  |
			g_arrSqare[1][0] = 0, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	| ■■ |
		break;
	case 1:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0,		//	| ■■ |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 0, g_arrSqare[1][3] = 0;	//	|■■  |
		break;
	case 2:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 0, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0,		//	|  ■ |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	|■■■ |
		break;
	case 3:
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 0, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0,		//	|■   |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	|■■■ |
		break;
	case 4:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0,		//	| ■  |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	|■■■ |
		break;
	case 5:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0,		//	| ■■ |
			g_arrSqare[1][0] = 0, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	| ■■ |
		break;
	case 6:
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 1,		//	|■■■■|
			g_arrSqare[1][0] = 0, g_arrSqare[1][1] = 0, g_arrSqare[1][2] = 0, g_arrSqare[1][3] = 0;	//	|    |
		break;

	default:
		break;
	}
	return nIndex;
}

void CopySqareToBack()
{
	int i = 0, j = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			g_arrBackGround[i][j + 3] = g_arrSqare[i][j];
		}
	}
}

void OnCreate()
{
	srand((unsigned int)time(NULL));
	CreateRandomSqare();
	CopySqareToBack();
}

void OnReturn(HWND hWnd)
{
	//打开定时器
	SetTimer(hWnd, DEF_TIMER1, 500, NULL);

}

void SqareDown()
{
	int i = 0, j = 0;
	for (i = 19; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == g_arrBackGround[i][j])
			{
				g_arrBackGround[i + 1][j] = g_arrBackGround[i][j];
				g_arrBackGround[i][j] = 0;
			}
		}
	}
}

void OnTimer(HWND hWnd)
{
	HDC hDC = GetDC(hWnd);//内核对象，使用完要释放
	SqareDown();
	//显示方块
	OnPaint(hDC);

	ReleaseDC(hWnd, hDC);
}