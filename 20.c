#include <stdio.h>
#include <string.h>

#define MAX_TASKS 15      // Maximum number of tasks (routine + custom)
#define MAX_NAME_LEN 50   // Maximum length of task name

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int priority;
    char date[20];
} Task;

void displayTasks(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks available.\n");
    } else {
        printf("\nTasks List:\n");
        printf("ID\tName\t\t\t\tPriority\tDue Date\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d\t%-20s\t\t\t%d\t\t%s\n", tasks[i].id, tasks[i].name, tasks[i].priority, tasks[i].date);
        }
    }
}

void modifyRoutine(Task tasks[], int taskCount) {
    int taskNumber;
    char newName[MAX_NAME_LEN];
    char newDate[20];
    int newPriority;

    printf("\nWhich routine task would you like to edit? (Choose ID between 1 and %d): ", taskCount);
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("Invalid task ID. Please try again.\n");
        return;
    }

    printf("Enter the new task name: ");
    scanf(" %[^\n]", newName);
    printf("Enter the new task priority (1-10): ");
    scanf("%d", &newPriority);
    printf("Enter the new due date (e.g., '2024-11-30'): ");
    scanf(" %[^\n]", newDate);

    strcpy(tasks[taskNumber - 1].name, newName);
    tasks[taskNumber - 1].priority = newPriority;
    strcpy(tasks[taskNumber - 1].date, newDate);

    printf("\nTask updated successfully!\n");
    displayTasks(tasks, taskCount);
}

void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task limit reached! Cannot add more tasks.\n");
        return;
    }

    Task newTask;
    newTask.id = *taskCount + 1;

    printf("Enter task name: ");
    scanf(" %[^\n]", newTask.name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &newTask.priority);
    printf("Enter due date of task: ");
    scanf(" %[^\n]", newTask.date);

    tasks[*taskCount] = newTask;
    (*taskCount)++;

    printf("Task added successfully!\n");
}

int main() {
    Task nightOwl[] = {
        {1, "Read a book", 5, "N/A"},
        {2, "Watch a movie", 3, "N/A"},
        {3, "Do some journaling", 7, "N/A"},
        {4, "Work on a personal project", 8, "N/A"},
        {5, "Call it a night!", 1, "N/A"}
    };

    Task earlyBird[] = {
        {1, "Go for a jog", 6, "N/A"},
        {2, "Make a healthy breakfast", 5, "N/A"},
        {3, "Start your work/studies", 9, "N/A"},
        {4, "Check your emails", 4, "N/A"},
        {5, "Plan the day ahead", 7, "N/A"}
    };

    Task customTasks[MAX_TASKS];
    int customTaskCount = 0;

    int choice, taskCount = 5;
    Task *selectedRoutine = NULL;

    printf("Welcome to the Enhanced Task Scheduler!\n");
    printf("Choose your routine:\n");
    printf("1. Night Owl\n");
    printf("2. Early Bird\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        selectedRoutine = nightOwl;
        printf("\nYou�ve chosen the Night Owl routine.\n");
    } else if (choice == 2) {
        selectedRoutine = earlyBird;
        printf("\nYou�ve chosen the Early Bird routine.\n");
    } else {
        printf("Invalid choice! Exiting.\n");
        return 1;
    }

    int option;
    do {
        printf("\nMenu:\n");
        printf("1. View Routine and Custom Tasks\n");
        printf("2. Modify a Routine Task\n");
        printf("3. Add a Custom Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nRoutine Tasks:\n");
                displayTasks(selectedRoutine, taskCount);
                printf("\nCustom Tasks:\n");
                displayTasks(customTasks, customTaskCount);
                break;

            case 2:
                modifyRoutine(selectedRoutine, taskCount);
                break;

            case 3:
                addTask(customTasks, &customTaskCount);
                break;

            case 4:
                printf("\nExiting the Task Scheduler. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (option != 4);

    return 0;
}

