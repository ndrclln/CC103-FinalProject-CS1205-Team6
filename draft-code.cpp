/*
NOTE:
    WHEN EDITING THE FILE FILL THIS UP FIRST:
    DATE & TIME:
    WHAT DID I DO/ CHANGE:
    COMMIT TITLE:
    WHO I AM:
-------------------------------------------
    DATE & TIME: April 24, 2026 | 10:31 PM
    WHAT DID I DO/ CHANGE: I CREATED A MENU OPTIONS FOR OUR APP OPENING
    COMMIY TITLE: Menu Options
    WHO I AM: ENDREA
*/

#include <iostream>
using namespace std;

// DEFINE COLORS FOR TERMINAL UI HERE:
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

#define RESET "\033[0m"


// DECLARE FUNCTIONS HERE:
int menuOptions(int menuChoice);

int main(){
    
    int menuChoice; // Choice for menu options

    cout << "\n===" << GREEN <<" Welcome to TaskPulse! " << RESET << "===\n" << endl;
    menuOptions(menuChoice); // Will show the menu options
    
    return 0;
}

// DEFINE FUNCTIONS HERE:

int menuOptions (int menuChoice) {
    do{
        cout << YELLOW << "\n ~~~ MENU OPTIONS ~~~ \n" << endl;
        cout << "(1) Add Task.\n" ;
        cout << "(2) View Tasks Queue \n";
        cout << "(3) Mark Task as Complete.\n" ;
        // cout << "(3) Undo Last Completed Task."  (PUT INSIDE VIEW COMPLETED TASK)
        cout << "(4) View Completed Tasks. \n" ;
        cout << "(5) Add Rewards \n";
        cout << "(6) End the Program.\n";

        cout << GREEN << "\nPlease enter your choice. ^-^ \n";
        cout << "Your Choice: " << RESET << endl;
        cin >> menuChoice;
        cin.ignore();

    
        switch (menuChoice) {
            case 1:
                cout << "You choose (1) :>\n"; 
                /*(Input function for choice 1) ;*/ 
                break;

            case 2: 
                cout << "You choose (2) :>\n"; 
                /*(Input function for choice 2) ;*/ 
                break;

            case 3: 
                cout << "You choose (3) :>\n"; 
                /*(Input function for choice 3) ;*/ 
                break;

            case 4: 
                cout << "You choose (4) :>\n"; 
                /*(Input function for choice 4) ;*/ 
                break;

            case 5: 
                cout << "You choose (5) :>\n"; 
                /*(Input function for choice 5) ;*/ 
                break;

            case 6: 
                cout << "You choose (6) :>\n"; break;
            
            default: cout << "Invalid choice, Try again! :< \n"; break;
        }

    }while (menuChoice != 6 ); 

        cout << YELLOW  << "\n==============================\n";
        cout << " Thank you for using the app!\n";
        cout << " Goodbye! See you next time. \n";
        cout << "==============================\n\n" << RESET ;

    return menuChoice;
}   