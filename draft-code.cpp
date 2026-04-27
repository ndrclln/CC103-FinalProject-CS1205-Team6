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
-------------------------------------------
    DATE & TIME: April 27, 2026
    WHAT DID I DO/CHANGE: Created viewCompletedTasks() function with undo support
    COMMIT TITLE: View Completed Tasks Feature
    WHO I AM: Althea 
-------------------------------------------
    DATE & TIME: April 27, 2029
    WHAT DID I DO/ CHANGE: Added a class, struct, for menu options 1 and 2
    COMMIT TITLE: Done menu options 1 and 2
    WHO I AM: Endrea
*/

#include <iostream>
using namespace std;

// DEFINE COLORS FOR TERMINAL UI HERE:
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

#define RESET "\033[0m"


//STRUCTS:
struct DeadlineDate{
    int year;
    int month;
    int day;
};

struct Task {
    string name;
    int effortLevel;
    DeadlineDate date;
    Task* next = nullptr;
};

class Queue{
    private:
        Task* front;
        Task* rear;
    public:
        Queue() {
            front = nullptr; 
            rear = nullptr;
        }

    void enqueue(Task* newTask) {
        if (front == nullptr){
            front = newTask;
            rear = newTask;
        } else{
            rear->next = newTask;
            rear = newTask;
        }
    };

    void display(){
        Task* temp = front;
        cout << YELLOW << "~~~ HERE IS/ARE YOUR TASKS ~~~" << RESET << endl;

        if(front == nullptr){
            cout << YELLOW << "Yey, you don't have a task to do!" << RESET << endl;
        }else{
            while(temp != nullptr){
                cout << GREEN << "Tasks Name: " << RESET << temp->name << endl;
                cout << GREEN << "Tasks Effort level (1: Low, 2: Medium, 3: High): " << RESET << temp->effortLevel << endl;
                cout << GREEN << "Tasks Deadline: " << RESET << temp->date.year << "/" << temp->date.month << "/" << temp->date.day << endl;;
                cout << endl;

                temp = temp->next;
                
            };
        }
    };
};

class priorityQueue{
    private:
        Task* front;
        Task* rear;
    public:
        priorityQueue() {
            front = nullptr; 
            rear = nullptr;
        }
    
    void enqueue(Task* newTask);
    
    void display(){
        Task* temp = front;
        cout << YELLOW << "~~~ HERE IS/ARE YOUR TASKS ~~~" << RESET << endl;

        if(front == nullptr){
            cout << YELLOW << "Yey, you don't have a task to do!" << RESET << endl;
        }else{
            while(temp != nullptr){
                cout << GREEN << "Tasks Name: " << RESET << temp->name << endl;
                cout << GREEN << "Tasks Effort level (1: Low, 2: Medium, 3: High): " << RESET << temp->effortLevel << endl;
                cout << GREEN << "Tasks Deadline: " << RESET << temp->date.year << "/" << temp->date.month << "/" << temp->date.day << endl;;
                cout << endl;

                temp = temp->next;
                
            };
        }
    };
};


// DECLARE FUNCTIONS HERE:
void menuOptions(Queue& queueTask); // DISPLAY MENU OPTIONS


// MAIN
int main(){
    Queue queueTask; // For task queing

    cout << "\n===" << GREEN <<" Welcome to TaskPulse! " << RESET << "===\n" << endl;
    menuOptions(queueTask); // Will show the menu options
    
    return 0;
}

// DEFINE FUNCTIONS HERE:

//----------------------MENU OPTIONS----------------------------
void menuOptions (Queue& queueTask) {
    int menuChoice; // Choice for menu options
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
        cout << "Your Choice: " << RESET;
        cin >> menuChoice;
        cin.ignore();

        cout << endl;
    
        switch (menuChoice) {
            case 1: {
                string name;
                int effortLevel;
                int year, month, day;

                cout << "You choose (1) :>\n"; 
                cout << GREEN << "Enter task name: " << RESET;
                getline(cin, name);

                cout << GREEN << "Enter effort level (1: low effort, 2: medium effort, 3: high effort): " << RESET;
                cin >> effortLevel;

                cout << GREEN << "Kindly enter the Deadline ^-^" << endl;
                cout << GREEN << "Enter year (YYYY): " << RESET;
                cin >> year;
                cout << GREEN << "Enter month (MM): " << RESET;
                cin >> month;
                cout << GREEN << "Enter day (DD): " << RESET;
                cin >> day;

                cout << YELLOW << "Check option 2 to view your tasks ^-^" << RESET;

                // Creating a new node for tasks
                Task* newTask = new Task;
                newTask->name = name;
                newTask->effortLevel = effortLevel;
                newTask->date.year = year;
                newTask->date.month = month;
                newTask->date.day = day;
                queueTask.enqueue(newTask);
                
                cout << endl;
                break;
            }
            case 2: {
                cout << "You choose (2) :>\n"; 
                queueTask.display();

                cout << endl;
                break;
            }
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
} 
 /*
bool isHigherPriority (Task* a, Task* b){

}
*/