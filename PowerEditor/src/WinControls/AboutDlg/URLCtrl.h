#ifndef URLCTRL_INCLUDED
#define URLCTRL_INCLUDED

//#include <windows.h>
#include <Window.h>

/* XOR mask for hand cursor */
/* Generated by HexEdit */

class URLCtrl : public Window {
public:
    URLCtrl():_hfUnderlined(0),_hCursor(0), _msgDest(NULL), _cmdID(0), _oldproc(NULL), \
        _linkColor(), _visitedColor(), _clicking(false) {_URL[0] = '\0';};

    void create(HWND itemHandle, TCHAR * link, COLORREF linkColor = RGB(0,0,255));
	void create(HWND itemHandle, int cmd, HWND msgDest = NULL);
    void destroy(){
		if(_hfUnderlined)
                ::DeleteObject(_hfUnderlined);
	        if(_hCursor)
                ::DestroyCursor(_hCursor);
    };

protected :
    TCHAR	 _URL[MAX_PATH];
    HFONT	_hfUnderlined;
    HCURSOR	_hCursor;

	HWND _msgDest;
	unsigned long _cmdID;

    WNDPROC  _oldproc;
    COLORREF _linkColor;
    COLORREF _visitedColor;
    bool  _clicking;

    static LRESULT CALLBACK URLCtrlProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
        return ((URLCtrl *)(::GetWindowLongPtr(hwnd, GWL_USERDATA)))->runProc(hwnd, Message, wParam, lParam);
    };
    LRESULT runProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
};

#endif //URLCTRL_INCLUDED
