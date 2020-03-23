/*------- HEADER FILE -------*/
#include <bits/stdc++.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

/*------- Clear Console Color Function (Source: Google) -------*/
void SetColor(int ForgC){
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the foreground color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void ClearConsoleToColors(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}
void SetColorAndBackground(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

/*------- Console Coordinate Function -------*/
COORD coord = {0,0};
void gotoxy(int x, int y){
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*------- Title -------*/
void MainInterface(){
    SetColor(7);
    gotoxy(28,2);
        cout << "Interior Material Calculator";
    SetColor(8);
    gotoxy(17,3);
        cout << "==================================================";

    while(1){

        int partition, runningFeet;

        SetColor(7);
        gotoxy(18,5);
        cout << "Enter Partition: ";
        SetColor(12);
        cin >> partition;

        SetColor(7);
        gotoxy(44,5);
        cout << "Enter Running Feet: ";
        SetColor(12);
        cin >> runningFeet;

        SetColor(7);
        gotoxy(26,9);
        cout << ".....: Necessary Materials :.....";

        gotoxy(30,11);
        cout << "Join Post      : ";
        SetColor(12);
        cout << partition*8;
        SetColor(7);
        cout << " feets";

        gotoxy(30,12);
        cout << "Top            : ";
        SetColor(12);
        cout << runningFeet;
        SetColor(7);
        cout << " feets";

        gotoxy(30,13);
        cout << "Middle Bit     : ";
        SetColor(12);
        cout << runningFeet;
        SetColor(7);
        cout << " feets";

        gotoxy(30,14);
        cout << "Wire Box       : ";
        SetColor(12);
        cout << runningFeet*2;
        SetColor(7);
        cout << " feets";

        gotoxy(30,15);
        cout << "Glass Side     : ";
        SetColor(12);
        cout << runningFeet+2;
        SetColor(7);
        cout << " feets";

    }
}

/*------- Main Function -------*/
int main(){
    ClearConsoleToColors(0,0);
    SetConsoleTitle("Interior Material Calculator");
    MainInterface();
}

void print_heading(const char title[]){
    SetColor(10);
    SetColorAndBackground(31,3);
    gotoxy(45,8);
        cout << title;
    SetColorAndBackground(17,15);
}
