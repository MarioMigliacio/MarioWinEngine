#include <Windows.h>

// https://docs.microsoft.com/en-us/windows/desktop/winprog/using-the-windows-headers
// https://wiki.winehq.org/List_Of_Windows_Messages
// https://docs.microsoft.com/en-us/windows/desktop/winmsg/window-class-styles
// https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes
// https://msdn.microsoft.com/en-us/library/windows/desktop/ms633559(v=vs.85).aspx

LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
		case WM_CLOSE:
			PostQuitMessage( 25 );	break;
	}

	return DefWindowProc( hWnd, msg, wParam, lParam );
}

int CALLBACK WinMain(
	HINSTANCE		hInstance,
	HINSTANCE		hPrevInstance,
	LPSTR			lpCmdLine,
	int				nCmdShow )
{
	const auto wcName = "MarioWinEngine";
	const auto exWndName = "Mario's Window";

	// Register the Window
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof( wc );
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hIconSm = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = wcName;
	RegisterClassEx( &wc );

	// Create the Window
	HWND hWnd = CreateWindowEx(
		0,
		wcName, exWndName,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		250, 250, 1280, 720,
		nullptr, nullptr, hInstance, nullptr
	);

	// Display the Window
	ShowWindow( hWnd, SW_SHOW );

	// message pump
	MSG msg;
	BOOL gResult;
	while( ( gResult = GetMessage( &msg, nullptr, 0, 0 ) ) > 0 )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	if( gResult == -1 )
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}

	return 0;
}