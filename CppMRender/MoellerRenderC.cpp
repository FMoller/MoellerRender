// MoellerRenderC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
