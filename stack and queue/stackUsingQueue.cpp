#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q;

public:
    bool isEmpty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }

    void push(int value) {
        q.push(value);

        // Move previous elements behind the newly inserted element
        int n = q.size();

        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << value << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << q.front() << " popped from stack\n";
        q.pop();
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        return q.front();
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        queue<int> temp = q;

        cout << "Stack elements from top to bottom: ";

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << '\n';
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Top";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                if (!stack.isEmpty()) {
                    cout << "Top element: " << stack.top() << '\n';
                }
                break;

            case 4:
                stack.display();
                break;

            case 5:
                cout << "Program terminated\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}