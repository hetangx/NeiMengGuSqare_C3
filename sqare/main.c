#include <Windows.h>
#include "resource.h"
#include "elsHead.h"
LRESULT CALLBACK PEluoSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);


//_In_ _In_opt_ is SAL, search MSDN Docs
//�����һ����, ���ڵ�Ψһ��ʶ,
int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	//��ʼ��������
	WNDCLASSEX wc;   //WNDCLASS����չ
	HWND hWnd;
	MSG mSg;

	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	//wc.hCursor = LoadCursor(NULL, IDC_ARROW); //����ϵͳ��꣬��һ����������Ϊ��
	wc.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_NODROP));//�û��Լ������ָ��ͼ�꣬Ҫ�������Դ��Ȼ�������к���� #include "resource.h"
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SELFTEST));  //�������ϵ�ͼ��
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SELFTEST));//�����������Ͻǵ�ͼ��
	wc.hInstance = hInstance;
	wc.lpfnWndProc = PEluoSi;//�ص�������ַ
	wc.lpszClassName = "els";//���������֣����ֲ�Ҫ�ظ���������ϵͳ����
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	
	//һ����12����Ա�����಻��

	//ע�ᴰ�ڶ���
	//ATOM //unsigned short 
	if (0 == RegisterClassEx(&wc))
	{
		//����  getlasterror
		int a = GetLastError(); //����
		return 0;
	}
	//��������
	hWnd=CreateWindowEx(WS_EX_TOPMOST,"els","���ɹŷ���",
		WS_OVERLAPPEDWINDOW,100,30,500,650,
		NULL,NULL,hInstance,NULL);
	if(NULL==hWnd)  //���ھ��   123   ���ڵ�Ψһ��ʶ
	{
		return 0;
	}

	//��ʾ����
	ShowWindow(hWnd, nShowCmd );//Ҳ����д  SW_SHOWNORMAL 
	//������ʾ����0   ������ʾ���ط�0

	//��Ϣѭ��
	while(GetMessage(&mSg, NULL, 0, 0))
	{
		//
		TranslateMessage(&mSg);//������Ϣ
		//
		DispatchMessage(&mSg);//�ַ���Ϣ��  ��׼��Ϣ  ������Ϣ ֪ͨ��Ϣ  �Զ�����Ϣ
	}	

	return 0;
}


LRESULT CALLBACK PEluoSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT pts;
	HDC hDC;
	switch (nMsg)
	{
	case WM_CREATE://�ص���������ĵ�һ����Ϣ�����ڴ�������ֻ����һ�Σ��������ݳ�ʼ��
		//���û�д��룬case���Ż���
		OnCreate();
		break;
	
	case WM_PAINT://�ص���������ĵڶ�����Ϣ
		hDC = BeginPaint(hWnd,&pts);//���ڿɲ�������ı�ʶ
			//�������ϵ�����
		OnPaint(hDC);
		//Rectangle(hDC,0,0,300,600);
		EndPaint(hWnd,&pts);
		break;

	case WM_KEYDOWN://
		switch (wParam)
		{
		case VK_RETURN:
			OnReturn(hWnd);
			break;
		case VK_LEFT:

			break;
		case VK_RIGHT:

			break;
		case VK_UP:

			break;
		case VK_DOWN:

			break;
		default:
			break;
		}
		break;

	case WM_TIMER:
		OnTimer(hWnd);
		break;

	case WM_DESTROY:
		KillTimer(hWnd, DEF_TIMER1);
		PostQuitMessage(0); //WM_CLOSE, WM_DESTROY, WM_QUIT
		break;
	}

	return DefWindowProc(hWnd, nMsg, wParam, lParam);//
}

