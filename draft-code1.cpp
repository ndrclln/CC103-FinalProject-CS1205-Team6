/*
NOTE:
    WHEN EDITING THE FILE FILL THIS UP FIRST:
    DATE & TIME:
    WHAT DID I DO/ CHANGE:
    COMMIT TITLE:
    WHO I AM:
-------------------------------------------
    DATE & TIME: April 27, 2026 | 10:33 PM
    WHAT DID I DO/ CHANGE: I ADDED MARK TASK COMPLETE. ADDED RANDOM REWARD SYSTEM. ADDED  REWARDS STORAGE
    COMMIY TITLE: ADD TASK COMPLETE AND REWARD
    WHO I AM: LYR
*/

#include <iostream>
#include <string>
using namespace std;

// DEFINE COLORS FOR TERMINAL UI HERE:
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

#define RESET "\033[0m"

// STRUCTS:
struct DeadlineDate
{
    int year;
    int month;
    int day;
};

struct Task
{
    string name;
    int effortLevel;
    DeadlineDate date;
    Task *next = nullptr;
};

struct Stack
{
    Task *top = nullptr;

    void push(Task *newTask)
    {
        newTask->next = top;
        top = newTask;
    }

    void display()
    {
        Task *temp = top;

        if (top == nullptr)
        {
            cout << "No completed tasks.\n";
            return;
        }

        while (temp != nullptr)
        {
            cout << "Completed Task: " << temp->name << endl;
            temp = temp->next;
        }
    }
};

class Queue
{
private:
    Task *front;
    Task *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    Task *getFront()
    {
        return front;
    }

    void enqueue(Task *newTask)
    {
        if (front == nullptr)
        {
            front = newTask;
            rear = newTask;
        }
        else
        {
            rear->next = newTask;
            rear = newTask;
        }
    };

    void display()
    {
        Task *temp = front;
        cout << YELLOW << "~~~ HERE IS/ARE YOUR TASKS ~~~" << RESET << endl;

        if (front == nullptr)
        {
            cout << YELLOW << "Yey, you don't have a task to do!" << RESET << endl;
        }
        else
        {
            while (temp != nullptr)
            {
                cout << GREEN << "Tasks Name: " << RESET << temp->name << endl;
                cout << GREEN << "Tasks Effort level (1: Low, 2: Medium, 3: High): " << RESET << temp->effortLevel << endl;
                cout << GREEN << "Tasks Deadline: " << RESET << temp->date.year << "/" << temp->date.month << "/" << temp->date.day << endl;
                ;
                cout << endl;

                temp = temp->next;
            };
        }
    };
};

class priorityQueue
{
private:
    Task *front;
    Task *rear;

public:
    priorityQueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    Task *getFront()
    {
        return front;
    }

    void enqueue(Task *newTask);

    void display()
    {
        Task *temp = front;
        cout << YELLOW << "~~~ HERE IS/ARE YOUR TASKS ~~~" << RESET << endl;

        if (front == nullptr)
        {
            cout << YELLOW << "Yey, you don't have a task to do!" << RESET << endl;
        }
        else
        {
            while (temp != nullptr)
            {
                cout << GREEN << "Tasks Name: " << RESET << temp->name << endl;
                cout << GREEN << "Tasks Effort level (1: Low, 2: Medium, 3: High): " << RESET << temp->effortLevel << endl;
                cout << GREEN << "Tasks Deadline: " << RESET << temp->date.year << "/" << temp->date.month << "/" << temp->date.day << endl;
                ;
                cout << endl;

                temp = temp->next;
            };
        }
    };
};

// DECLARE FUNCTIONS HERE:
void menuOptions(Queue &queueTask, Stack &completedTaskStack); // DISPLAY MENU OPTIONS

// REWARD SYSTEM
string rewards[50];
int rewardCount = 0;

// MAIN
int main()
{
    Queue queueTask; // For task queing

    Stack completedTaskStack; // For completed task stack

    cout << "\n===" << GREEN << " Welcome to TaskPulse! " << RESET << "===\n"
         << endl;
    menuOptions(queueTask); // Will show the menu options

    return 0;
}

// DEFINE FUNCTIONS HERE:

//----------------------MENU OPTIONS----------------------------
void menuOptions(Queue &queueTask)
{
    int menuChoice; // Choice for menu options
    do
    {
        cout << YELLOW << "\n ~~~ MENU OPTIONS ~~~ \n"
             << endl;
        cout << "(1) Add Task.\n";
        cout << "(2) View Tasks Queue \n";
        cout << "(3) Mark Task as Complete.\n";
        // cout << "(3) Undo Last Completed Task."  (PUT INSIDE VIEW COMPLETED TASK)
        cout << "(4) View Completed Tasks. \n";
        cout << "(5) Add Rewards \n";
        cout << "(6) End the Program.\n";

        cout << GREEN << "\nPlease enter your choice. ^-^ \n";
        cout << "Your Choice: " << RESET;
        cin >> menuChoice;
        cin.ignore();

        cout << endl;

        switch (menuChoice)
        {
        case 1:
        {
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
            Task *newTask = new Task;
            newTask->name = name;
            newTask->effortLevel = effortLevel;
            newTask->date.year = year;
            newTask->date.month = month;
            newTask->date.day = day;
            queueTask.enqueue(newTask);

            cout << endl;
            break;
        }
        case 2:
        {
            cout << "You choose (2) :>\n";
            queueTask.display();

            cout << endl;
            break;
        }
        case 3:
        {
            cout << "You choose (3)\n";

            if (queueTask.front == nullptr)
            {
                cout << "No tasks available.\n";
                break;
            }

            Task *finishedTask = queueTask.front;
            queueTask.front = queueTask.front->next;

            if (queueTask.front == nullptr)
            {
                queueTask.rear = nullptr;
            }

            completedTaskStack.push(finishedTask);

            cout << "Task completed: " << finishedTask->name << endl;

            if (rewardCount > 0)
            {
                int randomIndex = rand() % rewardCount;
                cout << "Reward earned: " << rewards[randomIndex] << endl;
            }
            else
            {
                cout << "No rewards available.\n";
            }

            break;
        }

        case 4:
            cout << "You choose (4) :>\n";
            /*(Input function for choice 4) ;*/
            break;

        case 5:
        {
            cout << "You choose (5)\n";

            string rewardName;
            getline(cin, rewardName);

            rewards[rewardCount] = rewardName;
            rewardCount++;

            cout << "Reward added successfully.\n";

            break;
        }

        case 6:
            cout << "You choose (6) :>\n";
            break;

        default:
            cout << "Invalid choice, Try again! :< \n";
            break;
        }

    } while (menuChoice != 6);

    cout << YELLOW << "\n==============================\n";
    cout << " Thank you for using the app!\n";
    cout << " Goodbye! See you next time. \n";
    cout << "==============================\n\n"
         << RESET;
}
/*
bool isHigherPriority (Task* a, Task* b){

}
*/
