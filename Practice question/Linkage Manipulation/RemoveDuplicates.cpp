/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//leetcode : 83. Remove Duplicates from Sorted List
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return NULL;

    ListNode* curr = head;
    ListNode* nextptr = head->next;

    while (nextptr != NULL) {
        if (curr->val == nextptr->val) {
            curr->next = nextptr->next;
            nextptr = curr->next;
        } else {
            curr = nextptr;
            nextptr = nextptr->next;
        }
    }

    return head;


    }
};