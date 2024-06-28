#include "Utils.hpp"

namespace Utils
{
    Console::Console(vec2_t screenSize)
    {
        m_vScreenSize.x = screenSize.x;
        m_vScreenSize.y = screenSize.y;
    };

    void Console::Exit(BOOL exitState)
    {
        system("pause");
        if (exitState)
        {
            exit(0);
        }
    }

    void Console::Clear()
    {
        system("cls");
    }

    void Console::TimedExit()
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        exit(0);
    }

    void Console::Log(const char* text)
    {
        printf(text);
    }

    __inline void Console::CheckSuccess(std::function<int()> fn, const char* errorMsg, const char* successMsg)
    {
        if (!fn())
        {
            Console::Log(errorMsg);
            Console::Exit(TRUE);
        }
        else
        {
            Console::Log(successMsg);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    };

    void Console::CalculateConsolePos(vec2_t& screenSize, vec2_t& consoleCalcSize, vec2_t& consolePos)
    {
        consolePos.x = (screenSize.x / 2.f) - consoleCalcSize.x;
        consolePos.y = (screenSize.y / 2.f) - (consoleCalcSize.y + 300);
    }

    void Console::SetConsoleInfo(const char* consoleName, vec2_t& consolePos, vec2_t& consoleTrueSize, BOOL showWindow)
    {
        constexpr const char* ofSucMsg = "[ INFO ]: Successfully changed console title.\n\n";
        constexpr const char* ofErrMsg = "[ ERROR ]: Failed to change console title.\n\n";
        constexpr const char* ffSucMsg = "[ INFO ]: Successfully moved console window.\n\n";
        constexpr const char* ffErrMsg = "[ ERROR ]: Failed to move console window.\n\n";

        HWND hWnd;
        hWnd = GetConsoleWindow();
        Console::CheckSuccess([&]() { return SetConsoleTitleA(consoleName); }, ofErrMsg, ofSucMsg);
        Console::CheckSuccess([&]() { return MoveWindow(hWnd, (int)consolePos.x, (int)consolePos.y, (int)consoleTrueSize.x, (int)consoleTrueSize.y, TRUE); }, ffErrMsg, ffSucMsg);
        if (showWindow)
        {
            ShowWindow(hWnd, TRUE);
        }
        else
        {
            ShowWindow(hWnd, FALSE);
        }
    }

    void Console::MoveWindowWrapper(int currentFolder, HWND hWnd, vec2_t screenSize, vec2_t folderSize, vec2_t folderPos, BOOL bRepaint)
    {
        constexpr const char* errorMsg = "[ ERROR ]: Failed to move folder window.\n\n";
        constexpr const char* successMsg = "[ INFO ]: Successfully moved folder window.\n\n";

        vec2_t vFolderPosRightSide = { 0, 0 };

        vFolderPosRightSide.x = screenSize.x - folderSize.x;
        vFolderPosRightSide.y = (screenSize.y) - (folderSize.y + 2.f);

        folderPos.x = 0.f;
        folderPos.y = (screenSize.y) - (folderSize.y + 2.f);

        switch (currentFolder)
        {
        case 0:
            Console::CheckSuccess([&]() { return MoveWindow(hWnd, (int)folderPos.x, (int)folderPos.y, (int)folderSize.x, (int)folderSize.y, bRepaint); }, errorMsg, successMsg);
            break;
        case 1:
            Console::CheckSuccess([&]() { return MoveWindow(hWnd, (int)folderPos.x, (int)folderPos.y, (int)folderSize.x, (int)folderSize.y, bRepaint); }, errorMsg, successMsg);
            break;
        case 2:
            Console::CheckSuccess([&]() { return MoveWindow(hWnd, (int)vFolderPosRightSide.x, (int)vFolderPosRightSide.y, (int)folderSize.x, (int)folderSize.y, bRepaint); }, errorMsg, successMsg);
            break;
        case 3:
            Console::CheckSuccess([&]() { return MoveWindow(hWnd, (int)folderPos.x, (int)folderPos.y, (int)folderSize.x, (int)folderSize.y, bRepaint); }, errorMsg, successMsg);
            break;
        case 4:
            Console::CheckSuccess([&]() { return MoveWindow(hWnd, (int)vFolderPosRightSide.x, (int)vFolderPosRightSide.y, (int)folderSize.x, (int)folderSize.y, bRepaint); }, errorMsg, successMsg);
            break;
        case 5:
            Console::CheckSuccess([&]() { return MoveWindow(hWnd, (int)folderPos.x, (int)folderPos.y, (int)folderSize.x, (int)folderSize.y, bRepaint); }, errorMsg, successMsg);
            break;
        case 6:
            Console::CheckSuccess([&]() { return MoveWindow(hWnd, (int)vFolderPosRightSide.x, (int)vFolderPosRightSide.y, (int)folderSize.x, (int)folderSize.y, bRepaint); }, errorMsg, successMsg);
            break;
        }
    }

    void Console::OpenFolders(int folderAmount, const char* folderName[7], const char* folderPath[7], vec2_t& screenSize, vec2_t& folderSize, vec2_t& folderPos)
    {
        constexpr const char* ofSucMsg = "[ INFO ]: Successfully opened folder window.\n\n";
        constexpr const char* ofErrMsg = "[ ERROR ]: Failed to open folder window.\n\n";
        constexpr const char* ffSucMsg = "[ INFO ]: Successfully found folder window.\n\n";
        constexpr const char* ffErrMsg = "[ ERROR ]: Failed to find folder window.\n\n";

        for (int i = 0; i < folderAmount; i++)
        {
            Console::CheckSuccess([&]() { return system(folderPath[i]); }, ofErrMsg, ofSucMsg);
            HWND hWnd;
            hWnd = FindWindowA(NULL, folderName[i]);
            Console::CheckSuccess([&]() {
                hWnd = FindWindowA(NULL, folderName[i]);
                return (int)hWnd; 
                }, ffErrMsg, ffSucMsg);
            Console::MoveWindowWrapper(i, hWnd, screenSize, folderSize, folderPos, TRUE);
        }

        Console::Log("[ INFO ]: Successfully opened all Folders.\n\n");
        Console::TimedExit();
    }
}