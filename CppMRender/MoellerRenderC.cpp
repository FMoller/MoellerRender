#include <iostream>
#include <cwchar>
#include <Windows.h>
#include <stdlib.h>


#define S_WIDTH 21;
#define S_HEIGHT 21;

unsigned char sCenterX;
unsigned char sCenterY;





void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void print_point_lc(unsigned char line, unsigned char column) {
    gotoxy( column,line );
    std::cout << char(219);
}

void print_point_xy(unsigned char x, unsigned char y) {
    char l = sCenterY + y;
    char c = sCenterX + x;
    print_point_lc(l, c);
}

int main()
{

    sCenterX = S_WIDTH;
    sCenterY = S_HEIGHT;
    sCenterX = sCenterX / 2;
    sCenterY = sCenterY / 2;
    //print_point_lc(1, 1);
    print_point_xy(0, 0);
    print_point_xy(1, 0);
    print_point_xy(0, 1);
    print_point_xy(0, -1);
    print_point_xy(-1, 0);

    gotoxy(0, 15);
}