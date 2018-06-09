#include <windows.h>
#include "resource.h"

int menuItemId;

LRESULT WINAPI WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT p;

    switch (message)                  /* handle the messages */
    {
    case WM_DESTROY:
        PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
        break;

    case WM_LBUTTONDOWN:
        InvalidateRect(hwnd, NULL, FALSE);
        break;

    case WM_PAINT:
        EndPaint(hwnd, &p);
        break;

    case WM_COMMAND:
        menuItemId = LOWORD(wParam);

        switch(menuItemId)
        {

        case ID_Exit:
            PostQuitMessage(0);
            break;
        }

        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;

    default:                      /* for messages that we don't deal with */
        return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

INT APIENTRY WinMain(HINSTANCE hi, HINSTANCE, LPSTR cmd, INT n)
{

    WNDCLASS wc;

    wc.hInstance = hi;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.lpszClassName = "Nayra";
    wc.lpszMenuName = MAKEINTRESOURCE(ID_Menu);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("Nayra", "Paint", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hi, NULL);
    ShowWindow(hwnd, n);
    UpdateWindow(hwnd);

    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
