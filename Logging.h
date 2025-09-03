#include <windows.h>
#include <iostream>
#define APPNAME "FBW"
inline void setConsoleAttribute(DWORD attr){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle,attr);
}
inline std::ostream& red(std::ostream& os){
    setConsoleAttribute(FOREGROUND_RED | FOREGROUND_INTENSITY);
    return os;
}
inline std::ostream& white(std::ostream& os){
    setConsoleAttribute(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return os;
}
inline std::ostream& green(std::ostream& os){
    setConsoleAttribute(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return os;
}
inline std::ostream& purple(std::ostream& os){
    setConsoleAttribute(FOREGROUND_RED | FOREGROUND_BLUE);
    return os;
}

#define LOG(x) std::cout << "[" << APPNAME << "]:" << x
#define LOG_ERROR(x) std::cerr << red << "[" << APPNAME << "]:" << x << white
#define LOG_SUCCESS(x) std::cerr << green << "[" << APPNAME << "]:" << x << white
