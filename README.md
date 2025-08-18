# ForceBorderlessWindow
Forces borderless window in any windowed process
## Description
When playing sekiro i found the fullscreen mode to be too annoying , you cannot alt+tab and the screen tearing is unplayable. <br>
But in windowed mode it worked fine , but sekiro does not have a borderless window option , so i coded a program to inject into the game
and force borderless window.
## Usage
step 1 : if you are using it on game or application besides sekiro , change the EXE_NAME in the fix.cpp file to your program name<br>
step 2 : compile Borderless.cpp using
```batch
g++ Borderless.cpp -o Borderless.exe
```
step 3 : put the exe in the same folder as game exe<br>
step 4 : create a shortcut of the game (not the exe)<br>
step 5 : set the target of the shortcut to Borderless.exe<br>
step 6 : Run Game through the shortcut<br>
