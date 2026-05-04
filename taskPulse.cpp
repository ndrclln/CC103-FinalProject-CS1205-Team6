// TASKPULSE: TASK REWARD ENGINE
// CC 103 - Data Structures and Algorithms
// Team 6 - De-QUEUE-tives
// Members: Endrea, Althea, Lyren

#include <iostream>
#include <iomanip>
#include <string> 
#include <cstdlib> //Librabry for randomization
using namespace std;

// DEFINE COLORS FOR TERMINAL UI HERE:
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"


//STRUCTS:
struct DeadlineDate{
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
    int effort;
    int month;
    int day;
    string rewardEarned;
    CompletedTask* next;
};

// ------ MARK TASK COMPLETE BY LYREN --------
struct Stack {
    Task* top = nullptr;

    void push(Task* newTask) {
        newTask->next = top;
        top = newTask;
    }
};

//--- COMPLETED TASK STACK NODE BY ENDREA ----- 

//Stack for completed tasks (global)
CompletedTask* completedTop = nullptr;

//Push a completed task onto the stack
void pushCompleted(string name, int effort, int month, int day, string reward) {
    CompletedTask* node = new CompletedTask{name, effort, month, day, reward, completedTop};
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

//Effort number to label
string effortLabel(int effort) {
    if (effort == 1) return "Low";
    if (effort == 2) return "Medium";
    return "High";
}
// REWARD SYSTEM | RECURSION
string rewards[50];
int rewardCount = 0;

string getReward(int count) {
    if (count == 0) {               // To stop recursing
        return rewards[rand() % rewardCount];
    }
    return getReward(count - 1);    // Recursive call
}

// DECLARE FUNCTION FOR DETERMINING PRIORITY:
bool isHigherPriority (Task* a, Task* b); // 

// Class for REGULAR queuing of tasks
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

    Task* dequeue() {
        if (front == nullptr) {
            return nullptr;
        }
        Task* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        temp->next = nullptr;
        return temp;
    };

    void display(){
        Task* temp = front;
        cout << YELLOW << "~~~ HERE IS/ARE YOUR" << RED << " REGULAR " << YELLOW << "TASKS ~~~" << RESET << endl;

        if(front == nullptr){
            cout << YELLOW << "Yey, you don't have a task to do!" << RESET << endl;
        }else{
            while(temp != nullptr){
                cout << GREEN << "Tasks Name: " << RESET << temp->name << endl;
                cout << GREEN << "Tasks Effort level (1: Low, 2: Medium, 3: High): " << RESET << temp->effortLevel << endl;
                cout << GREEN << "Tasks Deadline: " << "2026" << "/" << temp->date.month << "/" << temp->date.day << endl;;
                cout << endl;

                temp = temp->next;
            }; 
        };
    }
};


//FUNCTION DEFINITION HERE FOR PRIORITY ORDER
bool isHigherPriority (Task* a, Task* b){

    // Comparing the months
    if (a->date.month < b->date.month){
        return true;
    }
    if (a->date.month > b->date.month){
        return false;
    }

    // If months are the SAME then compare day
    if (a->date.day < b->date.day){
        return true;
    }
    if (a->date.day > b->date.day){
        return false;
    }

    // If day are the SAME then compare effort level
    // If a has greater priority level then it will be prioritized
    if (a->effortLevel > b->effortLevel){
        return true;
    }
    if (a->effortLevel < b->effortLevel){
        return false;
    }

    return false;
}

//Class for the PRIORITY tasks
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

    Task* dequeue() {
        if (front == nullptr) return nullptr;
        Task* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        temp->next = nullptr;
        return temp;
    }
    
    void display(){
        Task* temp = front;
        cout << YELLOW << "~~~ HERE IS/ARE YOUR " << RED << "PRIORITY" << YELLOW << " TASKS ~~~" << RESET << endl;

        if(front == nullptr){
            cout << YELLOW << "Yey, you don't have a priority task, do other tasks!" << RESET << endl;
        }else{
            while(temp != nullptr){
                cout << GREEN << "Tasks Name: " << RESET << temp->name << endl;
                cout << GREEN << "Tasks Effort level (1: Low, 2: Medium, 3: High): " << RESET << temp->effortLevel << endl;
                cout << GREEN << "Tasks Deadline: " << RESET << "2026" <<"/" << temp->date.month << "/" << temp->date.day << endl;;
                cout << endl;

                temp = temp->next;
                
            };
        }
    };
};


//----- VIEW COMPLETED TASKS (with Undo option)  BY THEA ------
void viewCompletedTasks(Queue& queueTask, PriorityQueue& priorityTask) {
    cout << YELLOW << "\n ~~~ COMPLETED TASKS ~~~ \n" << RESET << endl;

    if (isCompletedEmpty()) {
        cout << RED << " Please do your tasks first! ^-^\n" << RESET;
        return;
    }

    // Display all completed tasks (traverse stack without destroying it)
    CompletedTask* current = completedTop;
    int count = 1;
    cout << left;
    cout << CYAN
         << setw(20) << "Task Name"
         << setw(20) << "| Effort"
         << setw(20) << "| Deadline"
         << "|Reward Earned\n"
         << RESET;
    cout << "--------------------------------------------------------------------------------" << "\n";

    while (current) {
        cout << setw(20) << current->name
             << setw(20) << effortLabel(current->effort)
             << setw(20) << ("2026/" + to_string(current->month) + "/" + to_string(current->day))
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
            
            // Create a new Task node from completed task
            Task* restoredTask = new Task;
            restoredTask->name = undone->name;
            restoredTask->effortLevel = undone->effort;
            restoredTask->date.month = undone->month;
            restoredTask->date.day = undone->day;

            // Route back to correct queue based on effort
            if (undone->effort == 3) {
                priorityTask.enqueue(restoredTask);
            } else {
                queueTask.enqueue(restoredTask);
            }
            delete undone;
        } else {
            cout << RED << " Nothing to undo!\n" << RESET;
        }
    }
}


// DECLARE FUNCTIONS HERE:
void menuOptions(Queue& queueTask, PriorityQueue& priorityTask, Stack& completedTaskStack); // DISPLAY MENU OPTIONS




// MAIN
int main(){
    Queue queueTask; // For task queing
    PriorityQueue priorityTask; // For priority task
    Stack completedTaskStack;

    cout << "\n====" << GREEN <<" Welcome to TaskPulse! " << RESET << "====";
    cout << "\n  ==" << GREEN <<" Your task companion. " << RESET << " ==";
    cout << "\n     " << GREEN <<" by De-Queue-Tives " << RESET << "   " << endl;
    menuOptions(queueTask, priorityTask, completedTaskStack); // Will show the menu options
    
    return 0;
}

// DEFINE FUNCTIONS HERE:

//----------------------MENU OPTIONS----------------------------
void menuOptions (Queue& queueTask, PriorityQueue& priorityTask, Stack& completedTaskStack) {
    int menuChoice; // Choice for menu options
    do{
        cout << YELLOW << "\n   ~~~ MENU OPTIONS ~~~ \n";
        cout << "(1) Add Task.\n" ;
        cout << "(2) View Tasks Queue \n";
        cout << "(3) Mark Task as Complete.\n" ;
        cout << "(4) View Completed Tasks. \n" ;
        cout << "(5) Add Rewards \n";
        cout << "(6) End the Program.\n";

        cout << GREEN << "\nPlease enter your choice. ^-^ \n";
        cout << "Your Choice: " << RESET;
        cin >> menuChoice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            menuChoice = 0;
        }else{
            cin.ignore();
        }

        cout << endl;
    
        switch (menuChoice) {
            case 1: {
                string name;
                int effortLevel;
                int month, day;

                cout << "You choose (1) :>\n"; 
                cout << GREEN << "Enter task name: " << RESET;
                getline(cin, name);

                do{
                    cout << RED << "\nPlease input 1: Low, 2: Medium, 3: High" << endl; 
                    cout << GREEN << "Enter effort level: " << RESET;
                    cin >> effortLevel;
                    
                    //to avoid infinite looping 
                    //try and exeption handling for invalid input for menu options
                    if (cin.fail()) { 
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << RED << "Please enter numbers only. :<\n" << RESET;
                        } else if (effortLevel < 1 || effortLevel > 3) {
                            cin.ignore(1000, '\n');
                            cout << RED << "Choose between 1, 2, or 3 only. :3\n" << RESET;
                        }
                } while (cin.fail() || effortLevel < 1 || effortLevel > 3);


                cout << GREEN << "\nKindly enter the Deadline ^-^" << RESET << endl;
                do{
                cout << GREEN << "Enter month 2026-MM: " << RESET;
                cin >> month;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << RED << "Please enter numbers only. :<\n" << RESET;
                    } else if (month < 1 || month > 12) {
                        cin.ignore(1000, '\n');
                        cout << RED << "No, month must be between 1-12 only :>.\n" << RESET;
                    }
                } while (cin.fail() || month < 1 || month > 12);

                do{
                cout << GREEN << "Enter day 2026" << "-" << month << "-DD: " << RESET;
                cin >> day;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << RED << "Please enter numbers only. :<\\n" << RESET;
                    } else if (day < 1 || day > 31) {
                        cin.ignore(1000, '\n');
                        cout << RED << "Oh no! Days must be only between 1-31. :>\n" << RESET;
                    }
                } while (cin.fail() || day < 1 || day > 31);

                cout << YELLOW << "\nCheck option 2 to view your tasks ^-^" << RESET;

                // Creating a new node for tasks
                Task* newTask = new Task;
                newTask->name = name;
                newTask->effortLevel = effortLevel;
                newTask->date.month = month;
                newTask->date.day = day;

                // to traverse to the prio and queue
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
            case 3: {
                cout << "You choose (3) :>\n"; 
                Task* finishedTask = priorityTask.dequeue();
                if (finishedTask == nullptr) {
                    finishedTask = queueTask.dequeue();
                }
                if (finishedTask == nullptr) {
                    cout << RED << "No tasks available. :<\n" << RESET;
                    break;
                }

                completedTaskStack.push(finishedTask); // Lyren's stack

                string reward = "Add reward in menu (5) :3";
                if (rewardCount > 0) {
                    reward = getReward(rewardCount);  // ← recursive call
                }

                pushCompleted(finishedTask->name, finishedTask->effortLevel, finishedTask->date.month, finishedTask->date.day, reward); 

                cout << CYAN << "Task completed: " << finishedTask->name << RESET << endl;
                cout << CYAN << "Reward earned: " << reward << RESET << endl;

                break;
            }
            case 4: 
                cout << "You choose (4) :>\n"; 
                
                viewCompletedTasks(queueTask, priorityTask);
                break;

            case 5: {
                cout << "You choose (5) :>\n"; 
                cout << GREEN << "Enter reward name: " << RESET;
                string rewardName;
                getline(cin, rewardName);

                rewards[rewardCount] = rewardName;
                rewardCount++;

                cout << GREEN << "Finish tasks for your reward!^O^\n" << RESET;
                break;
            }

            case 6: 
                cout << "You choose (6) :>\n"; break;
            
            default: cout << "Invalid choice, Try again:<\n"; break;
        }

    }while (menuChoice != 6 ); 

        cout << YELLOW  << "\n==============================\n";
        cout << " Thank you for using the app!\n";
        cout << " Goodbye! See you next time. \n";
        cout << "==============================\n\n" << RESET ;
} 
