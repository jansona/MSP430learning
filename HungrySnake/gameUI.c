#include <windows.h>
#include <conio.h>
#include "gameUI.h"

void homePage(void)
{
    int i = 0;
    hideCursor();
    printf("----------------------------------------\n");
    for(i = 0; i < 10; i++)
    {
        printf("|\t\t\t\t       |\n");
    }
    printf("----------------------------------------\n");
    gotoXY(5, 13);
    printf("�������ʼ");
    _getch();         //�����ʹ�ò��Ǻ�ȷ�������һ�¡���ȷ����������getchar����
    initSnake();
    initFood();
    gotoXY(5, 13);
    printf("                                        ");
}

void hideCursor(void)
{
    CONSOLE_CURSOR_INFO cursorInfo = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoXY(int x, int y)
{
    COORD pos;
    pos.X = x - 1;
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
