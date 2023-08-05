// MoellerRenderC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cwchar>
#include <Windows.h>
#include <stdlib.h>

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void print_point_lc(unsigned char line, unsigned char column) {
    gotoxy( column,line );
    std::cout << char(219);
}

int main()
{
    
    print_point_lc(1, 1);
    print_point_lc(0, 0);
    print_point_lc(13, 13);
    print_point_lc(1, 11);
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
