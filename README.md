# FreeCS for game Counter-Strike
- External Menu
- Saveable System
- GUI project: https://github.com/Coslly/EasyGUI-Lightweight.git
- CS C++ Build in Release | x86
- CS2 C++ Build in Release | x64
## 😩It doesn't work!!!
You need to modify the offset at the top of the `Main.cpp` file content.

The offset will change every game update.

Or you can add the `FreeCS.ofs` file to the same directory.

Offsets List: https://github.com/a2x/cs2-dumper/blob/main/generated/offsets.hpp
```cpp
0x123456//dwLocalPlayerPawn
0x123456//dwEntityList
0x123456//dwViewAngles
0x123456//dwViewMatrix
```
## 🤩Showcase
![image](https://github.com/Coslly/FreeCS/blob/main/Show/S_1.png?raw=true)
![image](https://github.com/Coslly/FreeCS/blob/main/Show/S_2.png?raw=true)
![image](https://github.com/Coslly/FreeCS/blob/main/Show/S_3.png?raw=true)
![image](https://github.com/Coslly/FreeCS/blob/main/Show/S_4.png?raw=true)
# 💀Disclaimer
I am not responsible for anything that happens when you use this software.
