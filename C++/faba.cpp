//Script to minimize, maximize and restore window
//Pass commands (Show, Hide, Max) and window title as runtime arguments

#define UNICODE
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <winuser.h>

using namespace std;

string opt;
string name;

wstring str2ws(const string& s) {
    int len;
    int slen = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slen, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slen, buf, len);
    wstring res(buf);
    delete[] buf;
    return res;
}

int main(int argc, char const *argv[])
{
    opt = argv[1];
    name = argv[2];
    wstring wname = str2ws(name);
    LPCWSTR lname = wname.c_str();
    HWND hwnd = FindWindow(NULL, lname);

    if (hwnd != 0 && opt == "Show"){
        cout << "Window Found!" << endl;
        cout << "Handle: " << hwnd << endl;
        ShowWindow(hwnd, SW_NORMAL);
        SetForegroundWindow(hwnd);
    }
    else if (hwnd != 0 && opt == "Hide"){
        cout << "Window Found!" << endl;
        cout << "Handle: " << hwnd << endl;
        ShowWindow(hwnd, SW_MINIMIZE);
    }
    else if (hwnd != 0 && opt == "Max"){
        cout << "Window Found!" << endl;
        cout << "Handle: " << endl;
        ShowWindow(hwnd, SW_MAXIMIZE);
        SetForegroundWindow(hwnd);
    }
    else {
        cout << "Window not found! Check title or open the window first genius...." << endl;
    }

}
