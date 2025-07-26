//TASK 4 TO-DO LIST
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Task {
public:
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(string desc) {
        tasks.push_back(Task(desc));
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks.\n";
            return;
        }
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "✓" : " ") << "] " << tasks[i].description << "\n";
        }
    }

    void completeTask(int index) {
        if (index >= 1 && index <= tasks.size())
            tasks[index - 1].completed = true;
        else
            cout << "Invalid task number.\n";
    }

    void removeTask(int index) {
        if (index >= 1 && index <= tasks.size())
            tasks.erase(tasks.begin() + index - 1);
        else
            cout << "Invalid task number.\n";
    }
};

int main() {
    ToDoList todo;
    string choice;
    cout<<"Welcome to TO-DO LIST"<<endl;
    do {
        cout << "\nCommands:1/add | 2/view | 3/complete | 4/remove | 5/exit\n";
        cout << "Enter choice: ";
        getline(cin, choice);
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "add" || choice == "1") {
            string desc;
            cout << "Enter task: ";
            getline(cin, desc);
            todo.addTask(desc);
        } 
        else if (choice == "view" || choice == "2") {
            todo.viewTasks();
        } 
        else if (choice == "complete" || choice == "3") {
            int idx;
            cout << "Enter task number: ";
            cin >> idx;
            cin.ignore();
            todo.completeTask(idx);
        } 
        else if (choice == "remove" || choice == "4") {
            int idx;
            cout << "Enter task number: ";
            cin >> idx;
            cin.ignore();
            todo.removeTask(idx);
        } 
        else if (choice != "exit" && choice != "5") {
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != "exit" && choice != "5");

    cout <<"/...Exiting TO-DO LIST...\n";
    return 0;
}
