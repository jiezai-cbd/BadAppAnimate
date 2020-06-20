#include "CharacterVideo.h"

void CharacterVideo::renewfileName(char* fileName, int fileNo)
{
    sprintf(fileName, "%s%d%s", "baascii\\ba(", fileNo, ").txt");
}

void CharacterVideo::recursor(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, coord);
}