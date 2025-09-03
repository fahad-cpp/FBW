# ForceBorderlessWindow
Forces borderless window in any windowed process
## Description
When playing sekiro i found the fullscreen mode to be too annoying , you cannot alt+tab and the screen tearing is unplayable. <br>
But in windowed mode it worked fine , but sekiro does not have a borderless window option , so i coded a program to inject into the game
and force borderless window.
## Usage
step 1 : Run your game<br>
step 2 : Compile and Run Borderless.cpp using<br>
```batch
mkdir build
cd build
cmake ..
cmake --build .
FBW.exe
```
step 3 : Select your game from the menu<br>
And your program will become borderless!