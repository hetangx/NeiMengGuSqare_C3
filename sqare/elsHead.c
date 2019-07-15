#include "elsHead.h"

//����ȫ������,ʹ��char��ʡ�ռ�
char g_arrBackGround[20][10] = { 0 };//20��10�У�i��j��
char g_arrSqare[2][4] = { 0 };
int g_nSqareID = 0;
int g_nLine = 0;
int g_nList = 0;
/*
  0123456789
0|��������������������|	��*10	
1|������o��o��������|	��o���ɵ�3*3���飬�����Ͻ�����Ϊ(0,3),����
2|��������������������|	����CreateRandomSqare��switch�ṹ�У���
3|������ooo��������|	0, 1, 2, 3, 4��5��case��g_nLine��g_nList
4|��������������������|	��ʼ��Ϊ(0,3)
*/
void OnPaint(HDC hDC)
{
	//����������DC
	HDC hMemDC = CreateCompatibleDC(hDC);
	//����һ��ֽ
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDC, 500, 600);
	//������ź�ֽ
	SelectObject(hMemDC, hBitmapBack);

	PaintSqare(hMemDC);
	PaintSqare2(hMemDC);

	//�ڴ�DC����������DC
	BitBlt(hDC, 0, 0, 300, 600, hMemDC, 0, 0, SRCCOPY);

	//�ͷ�
	DeleteObject(hBitmapBack);
	DeleteDC(hMemDC);
	/*
	ע�⣺
	GetDC --- ReleaseDC
	Create...DC --- DeleteDC
	*/
}

void PaintSqare(HDC hMemDC)
{
	//���󷽿�
	Rectangle(hMemDC, 0, 0, 300, 600);

	/*
	//���Դ��룬ָ��ĳԪ��Ϊ1
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
				//��С����
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
				//������
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
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0,		//	|����  |
			g_arrSqare[1][0] = 0, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	| ���� |
		g_nLine = 0;
		g_nList = 3;
		break;
	case 1:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0,		//	| ���� |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 0, g_arrSqare[1][3] = 0;	//	|����  |
		g_nLine = 0;
		g_nList = 3;
		break;
	case 2:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 0, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0,		//	|  �� |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	|������ |
		g_nLine = 0;
		g_nList = 3;
		break;
	case 3:
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 0, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0,		//	|��   |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	|������ |
		g_nLine = 0;
		g_nList = 3;
		break;
	case 4:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0,		//	| ��  |
			g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	|������ |
		g_nLine = 0;
		g_nList = 3;
		break;
	case 5:
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0,		//	| ���� |
			g_arrSqare[1][0] = 0, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;	//	| ���� |
		g_nLine = 0;
		g_nList = 4;
		break;
	case 6:
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 1,		//	|��������|
			g_arrSqare[1][0] = 0, g_arrSqare[1][1] = 0, g_arrSqare[1][2] = 0, g_arrSqare[1][3] = 0;	//	|    |
		g_nLine = 0;
		g_nList = 3;//
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

void OnCreate()
{
	srand((unsigned int)time(NULL));
	CreateRandomSqare();
	CopySqareToBack();
}

void OnReturn(HWND hWnd)
{
	//�򿪶�ʱ��
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
	HDC hDC = GetDC(hWnd);//�ں˶���ʹ����Ҫ�ͷ�

	if (1 == CanSqareDown() && 1 == CanSqareDown2())
	{
		SqareDown();
		g_nLine++;
	}
	else
	{
		//1 -> 2
		Change1to2();
		//����������->����ײ��������µ��������
		CreateRandomSqare();
		//���Ƶ�����
		CopySqareToBack();
	}

	//��ʾ����
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
	//��������
	if (1 == CanSqareLeft()&&1== CanSqareLeft2())
	{
		HDC hDC = GetDC(hWnd);
		SqareLeft();
		g_nList--;
		//��ʾ����
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
		//��������
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
	switch (g_nSqareID)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	{
		//��ͨ����
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
		//�����β�����
		return ;
	case 6:
		//����
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
	//��Ҫ��ת�ķ��鸴�Ƴ���
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			arrSqare[i][j] = g_arrBackGround[g_nLine + i][g_nList + j];
		}
	}
	//���κ��ƻ�ȥ
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
			if (2 == g_arrBackGround[g_nLine][g_nList])
			{
				return 0;
			}
		}
	}

	//if (g_nList < 0 || g_nList>9)
	//{
	//	return 0;
	//}
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