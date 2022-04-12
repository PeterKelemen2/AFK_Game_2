#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

// Declaration of variables
void time_flowing();
void stuff_happening();
void print_scoreboard();
void options();
void top_bottom();
void spaces();
void print_score();
void UI();

// Declaration of functions
long long int score = 10;
int add = 5000;
int length = 1;

void UI(){
    HWND console = GetConsoleWindow();
  RECT ConsoleRect;
  GetWindowRect(console, &ConsoleRect);

   MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 500, 200, TRUE);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 70;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void time_flowing(){
    if(kbhit()){ // Core
        char x = getch(); // waiting for the input
       // options(); // Printing the options
            }
    score = score + add;
}

void top_bottom(){
    // "+--------------+" 9 + length + 2
        cout << "+";
    for(int i=0; i < 9+length; i++)
        cout << "-";
        cout << "+";
    cout << endl;
}

void spaces(){
    // "|            |"
        cout << "|";
    for(int i=0; i < 9+length; i++)
        cout << " ";
        cout << "|";
    cout << endl;
}

void print_score(){
    spaces();
    // "| Score: "(9 spaces) + length + " |" (2 spaces);
        cout << "| Score: " << score << " |" << endl;
    spaces();
}

void print_scoreboard(){
    long long aux = score ;
    length = 0;

    while(aux > 0){ // Getting score length everytime eeeeh
        aux = aux/10;
        length ++;
    }

    top_bottom();
    print_score();
    top_bottom();
}

int main ()
{
    UI();

    for(;;){
        system("CLS");

        print_scoreboard();
        time_flowing();
        Sleep(1000);
    }
}
