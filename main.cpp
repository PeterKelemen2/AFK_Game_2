#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

// Declaration of variables
void time_flowing();
void stuff_happening();
void print_stuff();
void options();

// Declaration of functions
long long int score = 10;
int add = 10;

void time_flowing(){
    if(kbhit()){ // Core
        char x = getch(); // waiting for the input
        options(); // Printing the options
            }
    Sleep(1000); // Same
}

void print_stuff(){
    cout << "+------------------+" << endl;
    cout << "|                  |" << endl;
    cout << setw(20) << "| Score: " << score << "|" << endl;
    cout << "|                  |" << endl;
    cout << "+------------------+" << endl;
}

int main ()
{
    for(;;){
        system("CLS");
        print_stuff();
        time_flowing;
        print_stuff();
    }
}
