
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
- Undo last completed task.
- Search tasks by deadline.
- Reward system for motivation.
##
## 🛠️Data Structures Used 
| Data Structure | Purpose | Reason |
|---------------|--------|--------|
| Stack | Undo last completed task | Follows LIFO principle |
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
   - Task is removed from queue
   - System randomly assigns a reward
##
