#include <windows.h>
#include <psapi.h>
#include <iostream>
#include <string>
BOOL EnumWindowsProc(HWND window,LPARAM lparam){
    
}
int makeborderless(std::string& exeName){
    HWND windowHandle = FindWindowA(NULL,exeName.c_str());
    if(!windowHandle){
        std::cerr << "Failed to find window handle of "+exeName+"\n";
        return 1;
    }
    LONG style = GetWindowLong(windowHandle,GWL_STYLE);
    style &= ~(WS_CAPTION | WS_THICKFRAME);
    SetWindowLong(windowHandle,GWL_STYLE,style);

    LONG exStyle = GetWindowLong(windowHandle, GWL_EXSTYLE);
    exStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
    SetWindowLong(windowHandle, GWL_EXSTYLE, exStyle);
    SetWindowPos(windowHandle,NULL,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
    return 0;
}
int main() {
    EnumWindows(EnumWindowsProc,0);
    return 0;
}
