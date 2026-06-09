//idea : use 3 pointer prev, curr, next
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void reverseLL(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    Node* nextptr;

    while(curr!=NULL){
        nextptr=curr->next; //store next node
        curr->next=prev;    //reverse the link
        prev=curr;         //move prev forward
        curr=nextptr;     //move curr forward
    }
    head=prev; //update head to new first node
}

int main(){
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=new Node(50);
    cout<<"Original Linked List: ";
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    reverseLL(head);
    cout<<"Reversed Linked List: ";
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    

    return 0;
}