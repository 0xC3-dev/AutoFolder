#include "AutoFolder.hpp"

int main()
{
    // Declare and initalize the Console class object. Pass the values to the constructor var members.
    Utils::Console* console = new Utils::Console(vec2_t((float)GetSystemMetrics(SM_CXSCREEN), (float)GetSystemMetrics(SM_CYSCREEN)));

    console->CalculateConsolePos(console->m_vScreenSize, console->m_vConsoleCalcSize, console->m_vConsolePos);
    console->SetConsoleInfo("Auto Folder", console->m_vConsolePos, console->m_vConsoleTrueSize, TRUE);
    console->OpenFolders(7, console->m_iSideSelection, console->m_cFolderName, console->m_cFolderPath, console->m_vScreenSize, console->m_vFolderSize, console->m_vFolderPos);
}