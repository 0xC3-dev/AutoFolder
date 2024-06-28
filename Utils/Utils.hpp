#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <functional>
#include "Vectors.hpp"

namespace Utils
{
    // Console Class container that stores all our variables and functions for the program. 
    class Console
    {
    private:
        // Add any private members as needed/wanted.
    public:
        // All the Vector 2 variables to store sizing and positioning values.
        vec2_t m_vScreenSize = { 0, 0 };
        vec2_t m_vConsoleTrueSize = { 400, 200 }; // You can change this to the size of your liking.
        vec2_t m_vConsoleCalcSize = { 200, 100 }; // Keep in mind that whatever values you have for (m_vConsoleTrueSize) these must be half for proper sizing.
        vec2_t m_vConsolePos = { 0, 0 };
        vec2_t m_vFolderSize = { 1288, 720 }; // You can change this to the size of your liking. (This will be the Windows explorer window size)
        vec2_t m_vFolderPos = { 0, 0 };

        // All the Const Char* variables to store the name of all the explorer windows you wish to open.
        const char* m_cFolderName[7] = {
            "This PC",
            "This PC",
            "This PC",
            "This PC",
            "This PC",
            "This PC",
            "This PC" };

        // All the Const Char* variables to store the path of all the explorer windows you wish to open.
        const char* m_cFolderPath[7] = {
            "explorer.exe file:\\",
            "explorer.exe file:\\",
            "explorer.exe file:\\",
            "explorer.exe file:\\",
            "explorer.exe file:\\",
            "explorer.exe file:\\",
            "explorer.exe file:\\" };

        // Class constructor. We use it to grab the monitor size when the class is initialized by passing in a vec2_t.
        Console(vec2_t screenSize);

        // Class deconstructor.
        ~Console() = default;

        // Helper function to check the return of other Functions and report return message.
        __inline void CheckSuccess(std::function<int()> fn, const char* errorMsg, const char* successMsg);

        // Helper function that wraps WinApi 'system("pause")' function. We supply exit state by passing a BOOL to the (exitState) param.
        void Exit(BOOL exitState);

        // Helper function that wraps WinApi 'system("cls")' function.
        void Clear();

        // Helper function we use to use to suspend the main programs thread before exiting.
        void TimedExit();

        // Helper function that wraps WinApi 'printf()' function. We use this to display the debug information.
        void Log(const char* text);

        // Helper Function we use to calculate the desired console postion.
        void CalculateConsolePos(vec2_t& screenSize, vec2_t& consoleCalcSize, vec2_t& consolePos);

        // Helper Function we use to change console title and apply the new console window position.
        void SetConsoleInfo(const char* consoleName, vec2_t& consolePos, vec2_t& consoleTrueSize, BOOL showWindow);

        /*
        *   This is a wrapper for the WinApi MoveWindow() function.
        *
        *   Here we add an extra parameters (int currentFolder) to determine if the window will be placed on the Left or Right side of the monitor.
        */
        void MoveWindowWrapper(int currentFolder, HWND hWnd, vec2_t screenSize, vec2_t folderSize, vec2_t folderPos, BOOL bRepaint);

        // Helper function we use to actually iterate through opening the desired amount of folder windows.
        void OpenFolders(int folderAmount, const char* folderName[7], const char* folderPath[7], vec2_t& screenSize, vec2_t& folderSize, vec2_t& folderPos);
    };
}