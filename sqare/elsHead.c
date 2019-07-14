#include "elsHead.h"

//背景全局数组,使用char节省空间
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
	PaintSqare2(hMemDC);

	//内存DC传递至窗口DC
	BitBlt(hDC, 0, 0, 300, 600, hMemDC, 0, 0, SRCCOPY);

	//释放
	DeleteObject(hBitmapBack);
	DeleteDC(hMemDC);
	/*
	注意：
	GetDC --- ReleaseDC
	Create...DC --- DeleteDC
	*/
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

	HBRUSH hWhiteRec;
	HBRUSH hColorRec = CreateSolidBrush(RGB(233, 27, 182));
	hWhiteRec = SelectObject(hMemDC, hColorRec);

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

	hColorRec = SelectObject(hMemDC, hWhiteRec);
	DeleteObject(hColorRec);
}

void PaintSqare2(HDC hMemDC)
{
	HBRUSH hWhiteRec;
	HBRUSH hColorRec = CreateSolidBrush(RGB(114, 179, 49));
	hWhiteRec = SelectObject(hMemDC, hColorRec);
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (2 == g_arrBackGround[i][j])
			{
				//画方块
				Rectangle(hMemDC, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
			}
		}
	}

	hColorRec = SelectObject(hMemDC, hWhiteRec);
	DeleteObject(hColorRec);
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
	SetTimer(hWnd, DEF_TIMER1, 150, NULL);

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

	if (1 == CanSqareDown() && 1 == CanSqareDown2())
	{
		SqareDown();
	}
	else
	{
		//1 -> 2
		Change1to2();
		//不可以下落->到达底部，产生新的随机方块
		CreateRandomSqare();
		//复制到背景
		CopySqareToBack();
	}

	//显示方块
	OnPaint(hDC);

	ReleaseDC(hWnd, hDC);
}

int CanSqareDown()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (1 == g_arrBackGround[19][i])
		{
			return 0;
		}
	}
	return 1;
}

int CanSqareDown2()
{
	int i = 0, j = 0;
	for (i = 19; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == g_arrBackGround[i][j])
			{
				if (2 == g_arrBackGround[i+1][j])
				{
					return 0;
				}
			}
		}
		
	}
	return 1;
}

void Change1to2()
{
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == g_arrBackGround[i][j])
			{
				g_arrBackGround[i][j] = 2;
			}
		}
	}
}

void OnLeft(HWND hWnd)
{ 
	//方块左移
	if (1 == CanSqareLeft()&&1== CanSqareLeft2())
	{
		HDC hDC = GetDC(hWnd);
		SqareLeft();
		//显示方块
		OnPaint(hDC);
		ReleaseDC(hWnd, hDC);
	}
}
void SqareLeft()
{
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == g_arrBackGround[i][j])
			{
				g_arrBackGround[i][j - 1] = g_arrBackGround[i][j];
				g_arrBackGround[i][j] = 0;
			}
		}
	}
}

int CanSqareLeft()
{
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		if (1 == g_arrBackGround[i][0])
		{
			return 0;
		}
	}

	return 1;
}

int CanSqareLeft2()
{
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == g_arrBackGround[i][j])
			{
				if (2 == g_arrBackGround[i][j - 1])
					return 0;
			}
		}
	}
	return 1;
}

void OnRight(HWND hWnd)
{
	if (1 == CanSqareRight()&&1==CanSqareRight2())
	{
		HDC hDC = GetDC(hWnd);
		//方块右移
		SqareRight();
		OnPaint(hDC);
		ReleaseDC(hWnd, hDC);
	}
	
}

void SqareRight()
{
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 9; j >= 0; j--)
		{
			if (1 == g_arrBackGround[i][j])
			{
				g_arrBackGround[i][j + 1] = g_arrBackGround[i][j];
				g_arrBackGround[i][j] = 0;
			}
		}
	}
}

int CanSqareRight()
{
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		if (1 == g_arrBackGround[i][9])
		{
			return 0;
		}
	}
	return 1;
}

int CanSqareRight2()
{
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 9; j >= 0; j--)
		{
			if (1 == g_arrBackGround[i][j])
			{
				if (2 == g_arrBackGround[i][j + 1])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

void OnDown(HWND hWnd)
{
	OnTimer(hWnd);
}