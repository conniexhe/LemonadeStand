#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

// Foreground color constants
const int fWHITE = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
const int fBLACK = 0;
const int fBLUE = FOREGROUND_BLUE;
const int fGREEN = FOREGROUND_GREEN;
const int fTEAL = FOREGROUND_BLUE | FOREGROUND_GREEN;
const int fRED = FOREGROUND_RED;
const int fPURPLE = FOREGROUND_RED | FOREGROUND_BLUE;
const int fBROWN = FOREGROUND_RED | FOREGROUND_GREEN;
const int fGREY = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
const int fBRIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const int fBRIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const int fBRIGHT_TEAL = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const int fBRIGHT_RED = FOREGROUND_RED| FOREGROUND_INTENSITY;
const int fBRIGHT_PURPLE = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const int fYELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const int fBRIGHT_WHITE = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;

// Background color constants
const int bWHITE = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
const int bBLACK = 0;
const int bBLUE = BACKGROUND_BLUE;
const int bGREEN = BACKGROUND_GREEN;
const int bTEAL = BACKGROUND_BLUE | BACKGROUND_GREEN;
const int bRED = BACKGROUND_RED;
const int bPURPLE = BACKGROUND_RED | BACKGROUND_BLUE;
const int bBROWN = BACKGROUND_RED | BACKGROUND_GREEN;
const int bGREY = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN;
const int bBRIGHT_BLUE = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
const int bBRIGHT_GREEN = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
const int bBRIGHT_TEAL = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
const int bBRIGHT_RED = BACKGROUND_RED| BACKGROUND_INTENSITY;
const int bBRIGHT_PURPLE = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
const int bYELLOW = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
const int bBRIGHT_WHITE = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;



HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
LPTSTR lpszString = "Character String";
DWORD cWritten; 
BOOL fSuccess; 
COORD coord; 
COORD coord2;
WORD wColors[3], backgroundColor, foregroundColor;
CHAR chFillChar; 

void initScreen(WORD fg, WORD bg) 
{

    // Copy this code, don't change anything
    // Fill an 80-by-25-character screen buffer with the space character.
    coord.X = 0;            // start at first cell
    coord.Y = 0;            //   of first row 
    chFillChar = ' '; 

    // Copy this code, don't change anything
    fSuccess = FillConsoleOutputCharacter(
        hOutput,          // screen buffer handle
        chFillChar,       // fill with spaces 
        80*200,            // number of cells to fill
        coord,            // first cell to write to 
        &cWritten);       // actual number written 

    // Set the foreground color (you can change the color)
    foregroundColor = fg;

    // Set the background color (you can change the color)
    backgroundColor = bg;


    // Copy this code, don't change anything
    fSuccess = FillConsoleOutputAttribute(
        hOutput,          // screen buffer handle
        foregroundColor | backgroundColor,  // set color
        80*200,            // number of cells to fill
        coord,            // first cell to write to 
        &cWritten);       // actual number written 
        
    SetConsoleTextAttribute(hOutput,  foregroundColor | backgroundColor);
        
}

void setForegroundColor(WORD fg) {
    foregroundColor = fg; 
    SetConsoleTextAttribute(hOutput,  foregroundColor | backgroundColor); // set text color
}

void setBackgroundColor(WORD bg) {
    backgroundColor = bg; 
    SetConsoleTextAttribute(hOutput,  foregroundColor | backgroundColor); // set text color
}

void setColors(WORD fg, WORD bg) {
    foregroundColor = fg;
    backgroundColor = bg; 
    SetConsoleTextAttribute(hOutput,  foregroundColor | backgroundColor); // set text color     
}

void setCoord(int x, int y) {
    coord2.X = x;
    coord2.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord2);
}     


