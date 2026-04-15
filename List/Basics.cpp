#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class list{
    public:
    Node *head;
    list(){
        head=NULL;
    }
    void push_front(int data){
        Node *newnode = new Node(data);
        if(head==NULL){
            head=newnode;
            return;
        }
        newnode->next=head;
        head=newnode;
    }
    void push_back(int data){
        Node *newnode = new Node(data);
        if(head==NULL){
            head=newnode;
            return;
        }
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    void pop_front(){
        if(head==NULL){
            return;
        }
        Node *temp=head;
        head=temp->next;
        delete temp;
    }
    void pop_back(){
        if(head==NULL){
            return;
        }
        if(head->next==NULL){
            delete head;
            head=NULL;
            return;
        }
        Node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
        
    }
bool search(int val){
    Node *temp = head;

    while(temp != NULL){
        if(temp->data == val){
            return true;
        }
        temp = temp->next;   // move forward
    }
    return false;
}
    void print(){
        Node *temp=head;
        int count=0;
        while(temp->next!=NULL){
            count++;
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data;
        count++;
        cout<<"length of list is "<< count;
    }
};
  int main(){
        list ll;
        ll.push_front(10);
        ll.push_front(20);
        ll.push_front(30);
        ll.push_back(40);
        ll.push_back(50);
        ll.print();
        cout<<endl;
        ll.pop_front();
        ll.print();
        cout<<endl;
        ll.pop_back();
        ll.print();
        cout<<endl;
        bool ans=ll.search(10);
        cout<<ans;
        return 0;
    }


