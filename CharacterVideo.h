//#pragma once

#ifndef CHARACTERVIDEO_H
#define CHARACTERVIDEO_H
#pragma comment(lib, "winmm")
#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include<fstream>
#include<time.h>
#include<Windows.h>
#include<mmsystem.h>
#include <tchar.h>
#include<string>

class CharacterVideo
{
public:
    HANDLE handle;
    COORD coord;
    void renewfileName(char* fileName, int fileNo); 
    void recursor(int x, int y);
};




#endif // !CHARACTERVIDEO_H

