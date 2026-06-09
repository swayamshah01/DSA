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
Node* middleOfList(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next; //move slow by 1
        fast=fast->next->next; //move fast by 2
    }
    return slow; //slow will be at the middle when fast reaches the end
}
int main(){
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=new Node(50);
    cout<<"Linked List: ";
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    Node* middle=middleOfList(head);
    if(middle!=NULL){
        cout<<"Middle of the Linked List: "<<middle->data<<endl;
    }else{
        cout<<"The linked list is empty."<<endl;
    }
    
    return 0;
}