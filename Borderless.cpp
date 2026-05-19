#include <Windows.h>
#include <string>
#include <iostream>
#include <psapi.h>
#include <vector>
#include "Logging.h"
#define MAX_SIZE 1024
struct Process{
    std::string windowName;
    std::string windowTitle;
};
std::vector<Process> runningProcesses = {};
BOOL CALLBACK EnumWindowsProc(HWND window,LPARAM lparam){
    DWORD processID = 0;
    GetWindowThreadProcessId(window,&processID);
    if(!IsWindowVisible(window) || IsIconic(window)){
        return TRUE;
    }

    char windowTitle[256];
    GetWindowTextA(window,windowTitle,sizeof(windowTitle));
    if(strlen(windowTitle) == 0){
        return TRUE;
    }

    if(HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,FALSE,processID)){
        char windowName[MAX_SIZE] = "<unknown>";
        HMODULE hMod;
        DWORD cbNeeded;
        if(EnumProcessModules(hProcess,&hMod,sizeof(HMODULE),&cbNeeded)){
            GetModuleBaseNameA(hProcess,hMod,windowName,sizeof(windowName));
        }
        runningProcesses.push_back(Process{windowName,windowTitle});
        CloseHandle(hProcess);
    }
    return TRUE;
}
int makeBorderless(const std::string& exeName){
    HWND windowHandle = FindWindowA(nullptr,exeName.c_str());
    if(!windowHandle){
        LOG_ERROR("Failed to find window handle of process:"<<exeName<<"\n");
        return 1;
    }
    LONG style = GetWindowLong(windowHandle,GWL_STYLE);
    style &= ~(WS_CAPTION | WS_THICKFRAME);
    SetWindowLong(windowHandle,GWL_STYLE,style);

    LONG exStyle = GetWindowLong(windowHandle, GWL_EXSTYLE);
    exStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
    SetWindowLong(windowHandle,GWL_EXSTYLE,exStyle);

    constexpr int width = 1920;
    constexpr int height = 1080;
    constexpr int x = 0;
    constexpr int y = 0;
    SetWindowPos(windowHandle,nullptr,x,y,width,height, SWP_NOZORDER | SWP_FRAMECHANGED);
    RECT rect = {};
    GetClientRect(windowHandle, &rect);
    LOG_SUCCESS("Successfully made "<<exeName<<" borderless.\n");
    return 0;
}
int main(){
    EnumWindows(EnumWindowsProc,0);
    int i = 1;
    for(const auto&[windowName, windowTitle] : runningProcesses){
        LOG(i<<"."<<purple<<windowName<<white<<":"<<windowTitle<<"\n");
        i++;
    }
    int choice = 0;
    LOG("Select your program:");
    std::cin>>choice;
    std::cin.get();
    makeBorderless(runningProcesses[choice-1].windowTitle);
    std::cin.get();
    return 0;
}
