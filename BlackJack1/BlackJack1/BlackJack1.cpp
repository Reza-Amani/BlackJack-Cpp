// BlackJack1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BlackJack1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

enum game_mode
{
	_manual,
	_auto
};

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	game_mode mode;
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			cout << "Hello\r\n";
			cout << "wanna play manually? m or a\r\n";
			mode =  (cin.get() == 'm') ? _manual : _auto;
			


			cout<<"any key to say bye\r\n";
			cin.get();
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
