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
void progress_bar();

// Declaration of functions
long long int score = 80000;
int add = 0;
int length = 1;
char key = 'b';
char flow;

void UI(){
    HWND console = GetConsoleWindow();
  RECT ConsoleRect;
  GetWindowRect(console, &ConsoleRect);

   MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 500, 300, TRUE);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 24;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void options(){
      cout << endl;
      cout << "Press 1 to add +10/sec (costs 100)" << endl;
      cout << "Press 2 to add +20/sec (costs 200)" << endl;
      cout << "Press 3 to add +30/sec (costs 300)" << endl;
      progress_bar();
}

void progress_bar(){
      cout << endl;
      int perc = (score * 100) / 100000;
      cout << "Progress: [";
            int space_p = 10-perc/10;
            // 1 stripe = 10%;
      for(int i=0; i<perc/10; i++)
            cout << "=";
      for (int i=0; i<space_p; i++)
            cout << " ";
      cout << "] " << perc << "%" << endl;
}

void time_flowing(){
      system("CLS");
    print_scoreboard();
    if(kbhit()){ // Core
        key = getch(); // waiting for the input

      switch(key){
      case '1':
            if(score >=100 ){
                  add += 10;
                  score -= 100;
            }
            else cout << endl << "Not enough points" << endl;
            break;
      case '2':
            if(score >=200 ){
                  add += 20;
                  score -= 200;
            }
            else cout << endl << "Not enough points" << endl;
            break;
      case '3':
            if(score >=300 ){
                  add += 30;
                  score -= 300;
            }
            else cout << endl << "Not enough points" << endl;
            break;
        }
            }
    score = score + add;
    Sleep(1000);
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

    cout << "+" << add << "/sec" << endl;
    options(); // Printing options
}

int main ()
{
    UI();

    for(;;){

        time_flowing();
        //Sleep(1000);

    }
}
