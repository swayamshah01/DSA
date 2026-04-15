//leetcode : 237. Delete Node in a Linked List\
/**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        next=NULL;
    }
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        // ListNode *temp=node->next;
        node->next=node->next->next;

    }
};

int main(){
    return 0;
}