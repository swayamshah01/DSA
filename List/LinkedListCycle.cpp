/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//code to detect cycle in linked list 
//leetcode : 141. Linked List Cycle
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        bool isCycle = false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
int main(){
    ListNode *head=new ListNode(3);
    head->next=new ListNode(2);
    head->next->next=new ListNode(0);
    head->next->next->next=new ListNode(-4);
    head->next->next->next->next=head->next; // creating a cycle
    Solution s;
    ListNode *cycleStart=s.detectCycle(head);
    if(cycleStart!=NULL){
        cout<<"Cycle starts at node with value: "<<cycleStart->val<<endl;
    }else{
        cout<<"No cycle detected."<<endl;
    }
}