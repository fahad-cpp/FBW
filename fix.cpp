#include <windows.h>
#include <iostream>
#define exe_name "Sekiro"
int main(){
    HWND windowHandle = FindWindowA(NULL,exe_name);
    if(!windowHandle){
        std::cerr << "failed to find sekiro handle\n";
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