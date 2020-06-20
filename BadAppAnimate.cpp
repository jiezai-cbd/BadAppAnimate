//解决办法：
//
//（1）首先必须在开头引入头文件#include <mmSystem.h>
//（2）在解决方案中>>>>右击选择>>>>属性>>>>配置属性 > >> > 链接器>>>>输入>>>>附加依赖项中，写入winmm.lib，方可。
#pragma comment(lib, "winmm")
//解决sprintf编译报错问题
#define _CRT_SECURE_NO_WARNINGS  

#include <iostream>
#include<fstream>
#include<time.h>
#include<Windows.h>
#include<mmsystem.h>
#include <tchar.h>
#include<string>
//#include<string.h>

using namespace std;

char a[4] = { '|','/','-','\\' };

class CharacterVideo
{
public:
    HANDLE handle;
    COORD coord;
    void renewfileName(char* fileName,int fileNo)
    {
        sprintf(fileName, "%s%d%s", "baascii\\ba(", fileNo, ").txt");
    }
    void recursor(int x, int y)
    {
        coord.X = x;
        coord.Y = y;
        handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(handle, coord);
    }
};

int main()
{
    /*================测试颜色字体输出=======================
    
    */
    /*
    cout << "原色testCOLOR（没有设置字体颜色）" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
        FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
    cout << "白色testCOLOR（红色绿色蓝色相加）" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    //设置红色
    cout << "红色testCOLOR（设置的颜色为红色）" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
        ;//设置绿色
    cout << "绿色testCOLOR（设置的颜色为绿色）" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    //设置蓝色
    cout << "蓝色testCOLOR（设置的颜色为蓝色）" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
        FOREGROUND_GREEN);//设置红色和绿色相加
    cout << "黄色testCOLOR（红色和绿色相加色）" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
        FOREGROUND_BLUE);//设置红色和蓝色相加
    cout << "粉色testCOLOR（红色和蓝色相加色）" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
        FOREGROUND_BLUE);//设置绿色和蓝色相加
    cout << "青色testCOLOR（绿色和蓝色相加色）" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
    //设置颜色，没有添加颜色，故为原色
    cout << endl;
  
    system("pause");
    */

    /*======================分隔符===================================*/

    CharacterVideo cv;
    cv.recursor(0, 0);
    char fileName[22] = {"baascii\\ba(0).txt"};
    string str;
    int i = 0,delayTime = 33;
    clock_t startTime, finishTime;
    ifstream File(fileName);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << "\t\t\t\t键入回车开始播放"<<endl;
    /*for (int i = 0; i < 29; i++)
        cout << "\n";*/
    ifstream fileBanner;
    fileBanner.open("banner.txt");
    string str1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    while (fileBanner.good())
    {
        getline(fileBanner, str1);
        cout << "\t\t";
        cout << str1<<endl;
        //break;
    }
    cout << endl;
    fileBanner.close();
    //突然发现我好沙雕。。这图片完全可以从文件中读出的。。。
   /* cout << "\t\tUu5IS255X5XI2svrriLIgQBBBBBBBZ57rr77J1S5XSSI5IS5S\n" <<
        //"U             LPRBBBRgdbqPPDgQBBBQXs\n" <<
        "\t\t5 SU2U55K  XBBBBg2s7          vLSgBQBQX  5S2215K\n" <<
        "\t\tI 21J1u  DQBBPv   vLLjj1J1j1JJvL   sqBQBP  UJJjX\n" <<
        "\t\t5 IJJv SBBRY  YYjYsvsLsYsYsLsLYLJsjL  uQBBI LLjI\n" <<
        "\t\tI I1 vQBBL LYJLsLYLLvLvLvvvLvvvLvYLsYsv LBBMr7JX\n" <<
        "\t\tX S JQB2 7YvsvYvLvsvsvL7v7L7v7vvLvLvYLsvv XBB7 K\n" <<
        "\t\t5  UBBv YsvL7L7LvsYJYsLYvL7v7vvv7vvLvLvYLs sBBJ\n" <<
        "\t\tI uQB7 JsvL7vvvvYY   vsYYvYvLvvvvvvvvvLvYLu vBBu\n" <<
        "\t\tY BBv JsvLvLvLvLLYXBqL  vJYsLYvY7Lvv7L7vvLYj JBB\n" <<
        "\t\t71BS JJvLvL7v7vLJ BBBBQIv  vJYYvYvLvv7vvvvYYs PBJ\n" <<
        "\t\tiBQ ssLLvv7LvLvsJ QBBBBBQRIL  vJYsvYvL7vvLvYLYrBg\n" <<
        "\t\t1Bq JvYvvvv7vvLYu QBQQQQBQBBMUv  vYvvvv7vvLvsY PB\n" <<
        "\t\tgBv7LLvvvv7Lvv7sJ QBQQRQRBQBBBQgU7 vvL7v7L7Lvs uB\n" <<
        "\t\tBB77LvvvLvv7v7LYu BBQRQMQRQQQQBBBBQvvvL7v7vvYLvvB\n" <<
        "\t\tBBrvLYvLvv7v7vvYJ QBQQMQRQMQQBQBBBBY7vvvvv7LvY7vQ\n" <<
        "\t\tgBs JLL7L7vvL7LLj QBQMQRQRQQBQBBdsr7v7v7L7vvLY JB\n" <<
        "\t\tsBP Jsvv7v7vvLvsJ QBQQQBQBQBBEJ7  vv7v7L7L7LLJ dB\n" <<
        "\t\tiBB jssvv7vvv7LLj QBBQBQBBDu7  LJYsvLvLvvvLvJv7Bg\n" <<
        "\t\tr2Bq uLYvLvL7v7YY BBBBBgu7  vsLsLYvvvLvL7LLsY qBv\n" <<
        "\t\tU JBBv uLYvv7vvvvs v  vJYsvLvL7v7vvvvvvLvss vBQ1\n" <<
        "\t\tS  jBBY JLLvLvv7YvYvJssLsvLvv7v7LvvvLvYLsY sBBj\n" <<
        "\t\t5 5 YBBS vvsvsvLvLvLvLvLvv7v7v7LvLvYLYvY7 XBBv q\n" <<
        "\t\tS Su 7QBBL vJsJLsLLvLvL7LvvvvvvvYLsLJYv sBBg vUS\n" << endl;
        //"2 UuYY 5QBRj  LJJJLLLsLsYJLsLYvsYjss  JBBB1 YsJX\n" <<
       // "X IuujU  bBBBPs   vvssuj1J1JuYLv   sdBBBb  1uJ1S\n" <<
        //"5 KXISXPq  PBBBBD5v7          7Y2gBBBBK  PKK5X5b\n" <<
        //"q             YIgQBBBBBQQRQQBQBBQd5v"<<endl;
        */
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
        FOREGROUND_GREEN);//设置红色和绿色相加
    cout << "\t\tCopyright © 2020/6/20 jeizai_cbd All rights reserved";
    cin.get();
    //异步播放音乐
    PlaySound(_T("BadApple.wav"),NULL,SND_FILENAME|SND_ASYNC);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
        FOREGROUND_BLUE);
    startTime = clock();
    while (i <= 6570)
    {
        //每30帧修真10秒
        if (i % 30 == 0)
            delayTime = 43;
        else
            //每帧之间间隔33秒（实际少了1/3，但在上面修正）
            delayTime = 33;
        cv.renewfileName(fileName,i);
        finishTime = clock();
        if ((finishTime - startTime) >= delayTime)
        {
            i++;
            File.open(fileName);
            while (File.good())
            {
                getline(File, str);
                cout << str;
            }
            File.close();
            //=======================
            //80格子，每帧占比：80/6570  6570/80帧后加载一格（82）
            //cout << endl;
            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  BACKGROUND_RED |
                BACKGROUND_BLUE | BACKGROUND_INTENSITY);
            cv.recursor(0, 26);
            cout<< " [";
            if (i % 82 == 0)
            {
                for (int j = i / 82; j > 0; j--)
                    //std::cout << "#";
                    cout << "_";
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY| FOREGROUND_RED |
                FOREGROUND_BLUE);
            //std::cout << "] ";
            cv.recursor(0, 27);
            std::cout << a[i % 4] << "正在加载中";
            
            //=======================
            
            startTime += delayTime;
            cv.recursor(0, 0);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                FOREGROUND_BLUE);
        }       
    }

    //cout << "Hello World!"<<endl;
    //cout << "\n\n\n";

    //cv.recursor(0, 0);
    //cout << "a" << endl;
    //cin.get();
    system("pause");
    return 0;
}

