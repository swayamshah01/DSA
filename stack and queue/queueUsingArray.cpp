#include<iostream>
using namespace std;

class queue{
    private:
        static const int MAX_SIZE = 100;
        int arr[MAX_SIZE];
        int front;
        int rear;
    public:
        queue(){
            front=0;
            rear=-1;
        }
        bool isempty(){
            return front>rear;
        }
        bool isfull(){
            return rear==MAX_SIZE-1;
        }
        void enqueue(int value){
            if(isfull()){
                cout<<"Queue Overflow\n";
                return;
            }
            rear++;
            arr[rear]=value;
            cout<<value<<" enqueued into queue\n";
        }
        void dequeue(){
            if(isempty()){
                cout<<"Queue Underflow\n";
                return;
            }
            cout<<arr[front]<<" dequeued from queue\n";
            front++;
        }
        void peek(){
            if(isempty()){
                cout<<"Queue is empty\n";
                return;
            }
            cout<<"Front element is: "<<arr[front]<<"\n";
        }
        void display(){
            if(isempty()){
                cout<<"Queue is empty\n";
                return;
            }
            cout<<"Queue elements from front to rear:\n";
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    return 0;
}