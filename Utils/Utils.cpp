#include "Utils.hpp"

namespace Utils
{
    Console::Console(vec2_t screenSize)
    {
        m_vScreenSize.x = screenSize.x;
        m_vScreenSize.y = screenSize.y;
    };

    void Console::Pause(BOOL exitState)
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

    __inline void Console::CheckSuccess(int success, const char* errorMsg, const char* successMsg)
    {
        if (success == 0)
        {
            Console::Log(errorMsg);
            Console::Pause(TRUE);
        }
        else
        {
            Console::Log(successMsg);
        }
    };

    void Console::CalculateConsolePos(vec2_t& screenSize, vec2_t& consoleCalcSize, vec2_t& consolePos)
    {
        consolePos.x = (screenSize.x / 2.f) - consoleCalcSize.x;
        consolePos.y = (screenSize.y / 2.f) - (consoleCalcSize.y + 300);
    }

    void Console::SetConsoleInfo(const char* consoleName, vec2_t& consolePos, vec2_t& consoleTrueSize, BOOL showWindow)
    {
        HWND hWnd;
        hWnd = GetConsoleWindow();
        Console::CheckSuccess(SetConsoleTitleA(consoleName), "[ ERROR ]: Failed to change console title.\n\n", "[ INFO ]: Successfully changed console title.\n\n");
        Console::CheckSuccess(MoveWindow(hWnd, (int)consolePos.x, (int)consolePos.y, (int)consoleTrueSize.x, (int)consoleTrueSize.y, TRUE), "[ ERROR ]: Failed to move console window.\n\n", "[ INFO ]: Successfully moved console window.\n\n");
        if (showWindow)
        {
            ShowWindow(hWnd, TRUE);
        }
        else
        {
            ShowWindow(hWnd, FALSE);
        }
    }

    void Console::MoveWindowWrapper(int currentFolder, int sideSelection[7], HWND hWnd, vec2_t screenSize, vec2_t folderSize, vec2_t folderPos, BOOL bRepaint)
    {
        vec2_t vFolderPosRightSide = { 0, 0 };

        vFolderPosRightSide.x = screenSize.x - folderSize.x;
        vFolderPosRightSide.y = (screenSize.y) - (folderSize.y + 2.f);

        folderPos.x = 0.f;
        folderPos.y = (screenSize.y) - (folderSize.y + 2.f);

        switch (currentFolder)
        {
        case 0:
            Console::CheckSuccess(MoveWindow(hWnd, (int)folderPos.x, (int)folderPos.y, (int)folderSize.x, (int)folderSize.y, bRepaint), "[ ERROR ]: Failed to move folder window.\n\n", "[ INFO ]: Successfully moved folder window.\n\n");
            break;
        case 1:
            Console::CheckSuccess(MoveWindow(hWnd, (int)folderPos.x, (int)folderPos.y, (int)folderSize.x, (int)folderSize.y, bRepaint), "[ ERROR ]: Failed to move folder window.\n\n", "[ INFO ]: Successfully moved folder window.\n\n");
            break;
        case 2:
            Console::CheckSuccess(MoveWindow(hWnd, (int)vFolderPosRightSide.x, (int)vFolderPosRightSide.y, (int)folderSize.x, (int)folderSize.y, bRepaint), "[ ERROR ]: Failed to move folder window.\n\n", "[ INFO ]: Successfully moved folder window.\n\n");
            break;
        case 3:
            Console::CheckSuccess(MoveWindow(hWnd, (int)folderPos.x, (int)folderPos.y, (int)folderSize.x, (int)folderSize.y, bRepaint), "[ ERROR ]: Failed to move folder window.\n\n", "[ INFO ]: Successfully moved folder window.\n\n");
            break;
        case 4:
            Console::CheckSuccess(MoveWindow(hWnd, (int)vFolderPosRightSide.x, (int)vFolderPosRightSide.y, (int)folderSize.x, (int)folderSize.y, bRepaint), "[ ERROR ]: Failed to move folder window.\n\n", "[ INFO ]: Successfully moved folder window.\n\n");
            break;
        case 5:
            Console::CheckSuccess(MoveWindow(hWnd, (int)folderPos.x, (int)folderPos.y, (int)folderSize.x, (int)folderSize.y, bRepaint), "[ ERROR ]: Failed to move folder window.\n\n", "[ INFO ]: Successfully moved folder window.\n\n");
            break;
        case 6:
            Console::CheckSuccess(MoveWindow(hWnd, (int)vFolderPosRightSide.x, (int)vFolderPosRightSide.y, (int)folderSize.x, (int)folderSize.y, bRepaint), "[ ERROR ]: Failed to move folder window.\n\n", "[ INFO ]: Successfully moved folder window.\n\n");
            break;
        }
    }

    void Console::OpenFolders(int folderAmount, int sideSelection[7], const char* folderName[7], const char* folderPath[7], vec2_t& screenSize, vec2_t& folderSize, vec2_t& folderPos)
    {
        for (int i = 0; i < folderAmount; i++)
        {
            Console::CheckSuccess(system(folderPath[i]), "[ ERROR ]: Failed to open folder window.\n\n", "[ INFO ]: Successfully opened folder window.\n\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            HWND hWnd;
            hWnd = FindWindowA(NULL, folderName[i]);
            Console::CheckSuccess((int)FindWindowA(NULL, folderName[i]), "[ ERROR ]: Failed to find folder window.\n\n", "[ INFO ]: Successfully found folder window.\n\n");
            Console::MoveWindowWrapper(i, sideSelection, hWnd, screenSize, folderSize, folderPos, TRUE);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        Console::Log("[ INFO ]: Successfully opened all Folders.\n\n");
        Console::TimedExit();
    }
}