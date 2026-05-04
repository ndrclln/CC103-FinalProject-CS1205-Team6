
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