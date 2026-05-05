
# TaskPulse: Smart Task Prioritization System.
## 🎯Description

TaskPulse is a task management system design to help students effectively manage overlapping deadlines and varying task difficulties. it assists users in prioritizing tasks based on urgency and effort while motivating productivity through a reward-based system.
#
## 📌Problem Statement
Students often struggles to decide which task to prioritize when multiple deadlines and workloads overlap. this leads to poor time management, stress, and incomplete important tasks.
##
## 💡Proposed Solution 
### TaskPulse helps users:
- Organize tasks based on deadlines and efforts.
- Automatically prioritize important tasks.
- Tracks completed tasks.
- Stay motivated through a reward system.

##
## ⚙️Features
- Add tasks with name, effort level, and deadline.
- Automatic tasks prioritization.
- Mark tasks as completed task.
- Display completed tasks.
- Reward system for motivation.
##
## 🛠️Data Structures Used 
| Data Structure | Purpose | Reason |
|---------------|--------|--------|
| Stack | Display completed tasks, Undo last completed task | Follows LIFO principle |
| Queue | Store normal tasks | Follows FIFO order |
| Priority Queue | Store urgent/high-effort tasks | Ensures high priority tasks are handled first |
##
## 🧠Algorithm
1. Display menu options:
   - (1) Add Task.
   - (2) View Task Queue
   - (3) Mark Task as Complete.
   - (4) View Completed Tasks.
   - (5) Add Rewards
   - (6) End the Program

2. When adding a task:
   - Input task name, effort level (1–3), and deadline
   - System determines if task goes to:
     - Priority Queue (urgent/high effort)
     - Regular Queue (normal tasks)

3. Prioritization Rules:
   - Earlier deadline = higher priority
   - If same deadline → higher effort first
   - If equal → FIFO order

4. When completing a task:
   - Task is removed from queue and traverse ro completed task.
   - System randomly assigns a reward
##
## 🔃Iterative vs Recursive Comparison
TaskPulse primarily uses an **iterative approach** — `while` loops handle all
queue traversal, task insertion, and display operations across `Queue`,
`PriorityQueue`, and the completed task stack.

A **recursive-style approach** appears in `getReward()`, which the function 
call its self effort level →  month to get the randomize reward.

| | Iterative | Recursive |
|---|---|---|
| **Speed** | Faster, no call overhead | Slightly slower |
| **Readability** | Clear for list traversal | Cleaner for comparisons |
| **Used for** | `enqueue()`, `display()` | `getReward()` |

Overall, iterative is more practical for TaskPulse since most operations
involve traversing linked lists.
##
## ✨Design Decisions

- **Effort level 3 → Priority Queue; 1–2 → Regular Queue** — reserves the
  priority lane only for genuinely high-effort tasks.
- **Linked lists over arrays** — allows dynamic insertion and removal without
  shifting or resizing elements.
- **Priority order: effort level → month → day** — mirrors real-world urgency;
  earlier deadline always wins, effort only breaks ties.
- **Random reward assignment** — keeps motivation high by making rewards
  unpredictable rather than fixed.
##
## 👤Team Members
- **Babao, Althea Clarine L.**
- **Castillo, Endrea Collin B.**
- **Rodriguez, Lyren D.**
##
## 🙏🏻Acknowledgements

We would like to express our sincere gratitude to **Ms. Fatima Marie Agdon**
for her guidance and support throughout the development of TaskPulse. Her
teachings in CC 103 - Data Structures and Algorithms gave us the foundation
needed to design and implement this project.

We also want to acknowledge each member of **Team 6 - De-QUEUE-tives** —
Endrea, Althea, and Lyren — for their dedication, collaboration, and hard
work in bringing this project to life. Every feature built and every bug
fixed was a team effort.

Finally, we extend our thanks to the online resources and references that
helped us better understand data structures, C++ implementation, and
software design — particularly in applying linked lists, stacks, queues,
and priority queues in a real-world context.
##
