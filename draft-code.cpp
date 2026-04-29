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
-------------------------------------------
    DATE & TIME: April 29, 2029
    WHAT DID I DO/ CHANGE: Added a class, struct, for priority task and compile Thea's work
    COMMIT TITLE: Done menu priority task and menu 4 compiled
    WHO I AM: Endrea
*/

#include <iostream>
#include <iomanip>
using namespace std;

// DEFINE COLORS FOR TERMINAL UI HERE:
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define CYAN "\033[36m"

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

struct CompletedTask {
    string name;
    int effort;           //1=Low, 2=Medium, 3=High
    string deadline;
    string rewardEarned;
    CompletedTask* next;
};

//--- COMPLETED TASK STACK NODE ---

//Stack for completed tasks (global)
CompletedTask* completedTop = nullptr;

//Push a completed task onto the stack
void pushCompleted(string name, int effort, string deadline, string reward) {
    CompletedTask* node = new CompletedTask{name, effort, deadline, reward, completedTop};
    completedTop = node;
}

//Pop the last completed task (for undo)
CompletedTask* popCompleted() {
    if (!completedTop) return nullptr;
    CompletedTask* temp = completedTop;
    completedTop = completedTop->next;
    temp->next = nullptr;
    return temp;
}

//Check if stack is empty
bool isCompletedEmpty() {
    return completedTop == nullptr;
}

//Helper: effort number to label
string effortLabel(int effort) {
    if (effort == 1) return "Low";
    if (effort == 2) return "Medium";
    return "High";
}

// VIEW COMPLETED TASKS (with Undo option)
void viewCompletedTasks() {
    cout << YELLOW << "\n ~~~ COMPLETED TASKS ~~~ \n" << RESET << endl;

    if (isCompletedEmpty()) {
        cout << RED << " No completed tasks yet!\n" << RESET;
        return;
    }

    // Display all completed tasks (traverse stack without destroying it)
    CompletedTask* current = completedTop;
    int count = 1;
    cout << left;
    cout << CYAN
         << setw(4)  << "#"
         << setw(20) << "Task Name"
         << setw(10) << "Effort"
         << setw(15) << "Deadline"
         << "Reward Earned\n"
         << RESET;
    cout << string(60, '-') << "\n";

    while (current) {
        cout << setw(4)  << count++
             << setw(20) << current->name
             << setw(10) << effortLabel(current->effort)
             << setw(15) << current->deadline
             << current->rewardEarned << "\n";
        current = current->next;
    }

    //Undo option
    cout << YELLOW << "\n (U) Undo Last Completed Task\n";
    cout << " (B) Back to Menu\n" << RESET;
    cout << GREEN << "Your choice: " << RESET;

    char choice;
    cin >> choice;
    cin.ignore();

    if (choice == 'U' || choice == 'u') {
        CompletedTask* undone = popCompleted();
        if (undone) {
            cout << GREEN << "\n \"" << undone->name << "\" has been moved back to your task queue!\n" << RESET;
            // Re-enqueue the task (call your enqueue function here)
            // enqueueTask(undone->name, undone->effort, undone->deadline);
            delete undone;
        } else {
            cout << RED << " Nothing to undo!\n" << RESET;
        }
    }
} 
// -----------

// DECLARE FUNCTIONS HERE:
bool isHigherPriority (Task* a, Task* b); // FOR DETERMINING PRIORITY
// declare here for ordering puropose

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

// FUNCTION DEFINITION HERE FOR ORDERING PURPOSE
bool isHigherPriority (Task* a, Task* b){
    // Year comparison
    if (a->date.year < b->date.year){
        return true;
    }
    if (a->date.year > b->date.year){
        return false;
    }

    // if years are = then compare month
    if (a->date.month < b->date.month){
        return true;
    }
    if (a->date.month > b->date.month){
        return false;
    }

    // if months are = then compare day
    if (a->date.day < b->date.day){
        return true;
    }
    if (a->date.day > b->date.day){
        return false;
    }

    // if day are = then compare effort level
    // If a has greater priority level then it will be prioritize
    if (a->effortLevel > b->effortLevel){
        return true;
    }
    if (a->effortLevel < b->effortLevel){
        return false;
    }

    return false;
}


class PriorityQueue{
    private:
        Task* front;
        Task* rear;
    public:
        PriorityQueue() {
            front = nullptr; 
            rear = nullptr;
        }
    
    void enqueue(Task* newTask){
        if(front == nullptr){
            front = newTask;
            rear = newTask;
        }
        else if(isHigherPriority(newTask, front)){
            newTask->next = front;
            front = newTask;
        }
        else{
            Task* temp = front;
            while(temp->next != nullptr && !isHigherPriority(newTask, temp->next)){
                temp = temp->next;
            }
            newTask->next = temp->next;
            temp->next = newTask;
        }
    }
    
    void display(){
        Task* temp = front;
        cout << YELLOW << "~~~ HERE IS/ARE YOUR " << RED << "PRIORITY" << YELLOW << " TASKS ~~~" << RESET << endl;

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
void menuOptions(Queue& queueTask, PriorityQueue& priorityTask); // DISPLAY MENU OPTIONS

// MAIN
int main(){
    Queue queueTask; // For task queing
    PriorityQueue priorityTask; // For priority task

    cout << "\n===" << GREEN <<" Welcome to TaskPulse! " << RESET << "===\n" << endl;
    menuOptions(queueTask, priorityTask); // Will show the menu options
    
    return 0;
}

// DEFINE FUNCTIONS HERE:

//----------------------MENU OPTIONS----------------------------
void menuOptions (Queue& queueTask, PriorityQueue& priorityTask) {
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

                if (effortLevel == 3){
                    priorityTask.enqueue(newTask);
                } else{
                    queueTask.enqueue(newTask);
                }
                
                cout << endl;
                break;
            }
            case 2: {
                cout << "You choose (2) :>\n";

                priorityTask.display();
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
                
                viewCompletedTasks();
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
