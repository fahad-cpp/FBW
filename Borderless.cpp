#include <windows.h>
#include <string>
#include <iostream>
const std::string EXE_NAME = "Sekiro";
int main(){
    std::string command = "start "+EXE_NAME+".exe";
    system(command.c_str());
    Sleep(2000);
    HWND windowHandle = FindWindowA(NULL,EXE_NAME.c_str());
    if(!windowHandle){
        std::cerr << "failed to find "+EXE_NAME+" handle\n";
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