#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Task class to represent a task
class Task {
private:
    string title;
    string description;
    bool completed;

public:
    Task(const string& title, const string& description)
        : title(title), description(description), completed(false) {}

    const string& getTitle() const {
        return title;
    }

    const string& getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

    void markCompleted() {
        completed = true;
    }
};

// TaskManager class to manage tasks
class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& title, const string& description) {
        Task newTask(title, description);
        tasks.push_back(newTask);
        cout << "Task added successfully!\n";
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task deleted successfully!\n";
        } else {
            cout << "Invalid task index!\n";
        }
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markCompleted();
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task index!\n";
        }
    }

    void displayAllTasks() {
       cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i << ". ";
            cout << "Title: " << tasks[i].getTitle() << ", ";
            cout << "Description: " << tasks[i].getDescription() << ", ";
            cout << "Completed: " << (tasks[i].isCompleted() ? "Yes" : "No") << "\n";
        }
    }
};

int main() {
    TaskManager taskManager;

    int choice;
    string title, description;
    int index;

    while (true) {
        cout << "Task Management Application\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Display All Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter task description: ";
                getline(cin, description);
                taskManager.addTask(title, description);
                break;

            case 2:
                cout << "Enter task index to delete: ";
                cin >> index;
                taskManager.deleteTask(index);
                break;

            case 3:
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                taskManager.markTaskAsCompleted(index);
                break;

            case 4:
                taskManager.displayAllTasks();
                break;

            case 5:
                cout << "Exiting the program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "\n";
    }

    return 0;
}
