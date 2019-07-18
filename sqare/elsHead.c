#include "elsHead.h"

//背景全局数组,使用char节省空间
char g_arrBackGround[20][10] = { 0 };//20行10列，i行j列
char g_arrSqare[2][4] = { 0 };
int g_nSqareID = 0;
int g_nLine = 0;
int g_nList = 0;
int g_nScore = 0;
/*
 *  0123456789
 *0|□□□□□□□□□□|	□*10	
 *1|□□□o■o□□□□|	由o构成的3*3方块，其左上角坐标为(0,3),故在
 *2|□□□■■■□□□□|	函数CreateRandomSqare的switch结构中，把
 *3|□□□ooo□□□□|	0, 1, 2, 3, 4这5个case的g_nLine于g_nList
 *4|□□□□□□□□□□|	初始化为(0,3)
 */
void OnPaint(HDC hDC)
{
	//创建兼容性DC
	HDC hMemDC = CreateCompatibleDC(hDC);
	//创建一张纸
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDC, 500, 650);
	//关联编号和纸
	SelectObject(hMemDC, hBitmapBack);


	PaintSqare(hMemDC);
	PaintSqare2(hMemDC);
	PaintScore(hMemDC);

	//内存DC传递至窗口DC
	BitBlt(hDC, 0, 0, 500, 600, hMemDC, 0, 0, SRCCOPY);
	
	//释放
	DeleteObject(hBitmapBack);
	DeleteDC(hMemDC);
	/*
	注意：
	GetDC --- ReleaseDC
	Create...DC --- DeleteDC
	*/
}

void PaintScore(HDC hMemDC)
{
	char strScore[10] = { 0 };
	Rectangle(hMemDC, 300, 0, 500, 600);
	//显示分数
	_itoa_s(g_nScore, strScore, 10, 10);
	TextOut(hMemDC, 400, 10, "分数", strlen("分数"));
	TextOut(hMemDC, 400, 32, strScore, strlen(strScore));
}

void OnCreate()
{
	srand((unsigned int)time(NULL));
	CreateRandomSqare();
	CopySqareToBack();
}
void PaintSqare(HDC hMemDC)
{
	int i = 0, j = 0;
	//画大方块
	HBRUSH hWhiteRec;
	HBRUSH hColorRec;
	Rectangle(hMemDC, 0, 0, 300, 600);

	/*
	//测试代码，指定某元素为1
	g_arrBackGround[2][4] = 1;
	g_arrBackGround[3][3] = 1;
	g_arrBackGround[3][4] = 1;
	g_arrBackGround[3][5] = 1;
	*/


	hColorRec = CreateSolidBrush(RGB(233, 27, 182));
	hWhiteRec = SelectObject(hMemDC, hColorRec);

	
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == g_arrBackGround[i][j])
			{
				//画小方块
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
	//switch(6)
	switch (nIndex)
	{
	case 0:
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0,		//	|■■  |
			g_arrSqare[1][0] = 0, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	| ■■ |
		g_nLine = 0;
		g_nList = 3;
		break;
	case 1:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0,		//	| ■■ |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 0, g_arrSqare[1][3] = 0;	//	|■■  |
		g_nLine = 0;
		g_nList = 3;
		break;
	case 2:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 0, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0,		//	|  ■ |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	|■■■ |
		g_nLine = 0;
		g_nList = 3;
		break;
	case 3:
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 0, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0,		//	|■   |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	|■■■ |
		g_nLine = 0;
		g_nList = 3;
		break;
	case 4:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0,		//	| ■  |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	|■■■ |
		g_nLine = 0;
		g_nList = 3;
		break;
	case 5:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0,		//	| ■■ |
			g_arrSqare[1][0] = 0, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	| ■■ |
		g_nLine = 0;
		g_nList = 4;
		break;
	case 6:
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 1,		//	|■■■■|
			g_arrSqare[1][0] = 0, g_arrSqare[1][1] = 0, g_arrSqare[1][2] = 0, g_arrSqare[1][3] = 0;	//	|    |
		g_nLine = 0;
		g_nList = 4;
		break;

	default:
		break;
	}

	g_nSqareID = nIndex;
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

	if (1 == CanSqareDown() && 1 == CanSqareDown2())
	{
		SqareDown();
		g_nLine++;
	}
	else
	{
		//1 -> 2
		Change1to2();
		DestroyOneLine();
		//
		if (0 == CanGameOver())
		{
			//结束程序
			KillTimer(hWnd, DEF_TIMER1);
			return 0;
		}
		//不可以下落->到达底部，产生新的随机方块
		CreateRandomSqare();
		//复制到背景
		CopySqareToBack();
	}

	//显示方块
	OnPaint(hDC);

	ReleaseDC(hWnd, hDC);
}

int CanGameOver()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (2 == g_arrBackGround[0][i])
		{
			//游戏结束
			MessageBox(NULL, "GameOver", "Tips", MB_OK);
			return 0;
		}
	}
	return 1;
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

void PaintSqare2(HDC hMemDC)
{
	int i = 0, j = 0;
	HBRUSH hWhiteRec;
	HBRUSH hColorRec = CreateSolidBrush(RGB(114, 179, 49));
	hWhiteRec = SelectObject(hMemDC, hColorRec);
	
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
int CanSqareDown2()
{
	int i = 0, j = 0;
	for (i = 19; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == g_arrBackGround[i][j])
			{
				if (2 == g_arrBackGround[i + 1][j])
				{
					return 0;
				}
			}
		}

	}
	return 1;
}
//123
void OnLeft(HWND hWnd)
{ 
	//方块左移
	if (1 == CanSqareLeft()&&1== CanSqareLeft2())
	{
		HDC hDC = GetDC(hWnd);
		SqareLeft();
		g_nList--;
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
		g_nList++;
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

void OnChangeSqare(HWND hWnd)
{
	HDC hDC = GetDC(hWnd);
	
	//switch (6)
	switch (g_nSqareID)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	{
		//普通变形
		if (1==CanSqareChangeShape())
		{
			ChangeSqare();
		}
		else
		{
			return ;
		}
		break;
	}
	case 5:
		//正方形不变形
		return ;
	case 6:
		//长条
		if (1 == CanLineSqareChange())
		{
			ChangeLineSqare();
		}
		break;
	}

	OnPaint(hDC);
	ReleaseDC(hWnd,hDC);
}

void ChangeSqare()
{
	int i = 0, j = 0;
	int nTemp = 2;
	char arrSqare[3][3] = { 0 };
	//把要旋转的方块复制出来
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			arrSqare[i][j] = g_arrBackGround[g_nLine + i][g_nList + j];
		}
	}
	//变形后复制回去
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			//g_arrBackGround[g_nLine + i][g_nList + j] = arrSqare[2 - j][i];
			g_arrBackGround[g_nLine + i][g_nList + j] = arrSqare[nTemp][i];
			nTemp--;
		}
		nTemp=2;
	}
}

int CanSqareChangeShape()
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (2 == g_arrBackGround[g_nLine+i][g_nList+j])
			{
				return 0;
			}
		}
	}

	if (g_nList < 0)
	{
		g_nList = 0;
	}
	else if (g_nList + 2 > 9)
	{
		g_nList = 7;
	}


	return 1;
}

void ChangeLineSqare()
{
	if (1 == g_arrBackGround[g_nLine][g_nList - 1])  //横着
	{
		//清零
		g_arrBackGround[g_nLine][g_nList - 1] = 0;
		g_arrBackGround[g_nLine][g_nList + 1] = 0;
		g_arrBackGround[g_nLine][g_nList + 2] = 0;

		if (2 == g_arrBackGround[g_nLine + 1][g_nList])
		{
			//元素赋值
			g_arrBackGround[g_nLine - 1][g_nList] = 1;
			g_arrBackGround[g_nLine - 2][g_nList] = 1;
			g_arrBackGround[g_nLine - 3][g_nList] = 1;
		}
		else if (2 == g_arrBackGround[g_nLine + 2][g_nList])
		{
			g_arrBackGround[g_nLine + 1][g_nList] = 1;
			g_arrBackGround[g_nLine - 1][g_nList] = 1;
			g_arrBackGround[g_nLine - 2][g_nList] = 1;
		}
		else
		{
			g_arrBackGround[g_nLine - 1][g_nList] = 1;
			g_arrBackGround[g_nLine + 1][g_nList] = 1;
			g_arrBackGround[g_nLine + 2][g_nList] = 1;
		}
	}
	else
	{
		//清零
		g_arrBackGround[g_nLine - 1][g_nList] = 0;
		g_arrBackGround[g_nLine + 1][g_nList] = 0;
		g_arrBackGround[g_nLine + 2][g_nList] = 0;

		if (2 == g_arrBackGround[g_nLine][g_nList + 1] ||9==g_nList)
		{
			//赋值
			g_arrBackGround[g_nLine][g_nList - 1] = 1;
			g_arrBackGround[g_nLine][g_nList - 2] = 1;
			g_arrBackGround[g_nLine][g_nList - 3] = 1;
			//标记改变
			g_nList -= 2;
		}
		else if (2 == g_arrBackGround[g_nLine][g_nList + 2]||8==g_nList)
		{
			g_arrBackGround[g_nLine][g_nList + 1] = 1;
			g_arrBackGround[g_nLine][g_nList - 1] = 1;
			g_arrBackGround[g_nLine][g_nList - 2] = 1;
			g_nList -= 1;
		}
		else if (2 == g_arrBackGround[g_nLine][g_nList - 1]|| 0 == g_nList)
		{
			g_arrBackGround[g_nLine][g_nList + 1] = 1;
			g_arrBackGround[g_nLine][g_nList + 2] = 1;
			g_arrBackGround[g_nLine][g_nList + 3] = 1;
			g_nList += 1;
		}
		else
		{
			//元素赋值
			g_arrBackGround[g_nLine][g_nList - 1] = 1;
			g_arrBackGround[g_nLine][g_nList + 1] = 1;
			g_arrBackGround[g_nLine][g_nList + 2] = 1;
		}

		
	}
}

int CanLineSqareChange()
{
	int i = 0, j = 0;
	for (i = 1; i < 4; i++)
	{
		if (2 == g_arrBackGround[g_nLine][g_nList + i]|| g_nList + i>9)
		{
			break;
		}
	}
	
	for (j = 1; j < 4; j++)
	{
		if (2 == g_arrBackGround[g_nLine][g_nList - j] || g_nList - j < 0)
		{
			break;
		}
	}

	if ((i - 1 + j - 1) < 3)
	{
		return 0;
	}

	return 1;
}

void DestroyOneLine()
{
	int i = 0, j = 0;
	int nSum = 0;
	int nTempi = 0;
	for (i = 19; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
		{
			nSum += g_arrBackGround[i][j];
		}
		if (20 == nSum)
		{
			//消除一行
			for (nTempi = i - 1; nTempi >= 0; nTempi--)
			{
				for (j = 0; j < 10; j++)
				{
					g_arrBackGround[nTempi + 1][j] = g_arrBackGround[nTempi][j];
					
				}
			}
			//使循环从头开始
			g_nScore++;
			i = 20;
		}
		nSum = 0;
	}
}

