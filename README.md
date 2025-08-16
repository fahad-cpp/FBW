# ForceBorderlessWindow
Forces borderless window in any windowed process
## Description
When playing sekiro i found the fullscreen mode to be too annoying , you cannot alt+tab and the screen tearing is unplayable. <br>
But in windowed mode it worked fine , but sekiro does not have a borderless window option , so i coded a program to inject into the game
and force borderless window.
## Usage
step 1 : if you are using it on game or application besides sekiro , change the exe_name in the fix.cpp file to your program name<br>
step 2 : compile fix.cpp using
```batch
g++ fix.cpp -o fix.exe
```
step 3 : Run your game/application<br>
step 4 : Run fix.exe<br>
Done.
