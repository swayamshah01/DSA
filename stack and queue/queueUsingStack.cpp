#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
private:
    stack<int> input;
    stack<int> output;

    void transferElements() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    void enqueue(int value) {
        input.push(value);
        cout << value << " inserted into queue.\n";
    }

    void dequeue() {
        transferElements();

        if (output.empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << output.top() << " removed from queue.\n";
        output.pop();
    }

    void front() {
        transferElements();

        if (output.empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Front element: " << output.top() << '\n';
    }

    bool isEmpty() {
        return input.empty() && output.empty();
    }
};

int main() {
    QueueUsingStack queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.front();

    queue.dequeue();
    queue.dequeue();

    queue.front();

    return 0;
}