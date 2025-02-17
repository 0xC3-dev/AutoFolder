# AutoFolder
Automate opening Folders for a smoother workspace

## Setup
* No external dependencies need to be included.
* ```C++ Language Standard: ISO C++20 Standard (/std:c++20)```
* ```C Language Standard: ISO C17 (2018) Standard (/std:c17)```
* ```Character Set: Use Multi-Byte Character Set```
* ```Optimizations have been enabled with the preset of favoring speed```

## Changelog
* UPDATE #1 | 06/27/24 : Initial release.
* UPDATE #2 | 06/28/24 : Refactored Console::Pause(); to Console::Exit();. Updated Console::CheckSuccess(); first param to take in proper function and handle return value. Cleaned up codebase.

## TODO
* GUI: Add a graphical user interface for a sleeker look.
* Folder Selection: Add option for user to input custom amount of folders to open along with the paths within the GUI.
* Config System: Add a config system so user can save/load several configurations of their folder setup.

## NOTE
* This program may be buggy on Windows 11 (this was tested and ran on Windows 10). If you wish to improve upon the codebase, feel free to make pull requests. Meaningful contributions are always welcome!