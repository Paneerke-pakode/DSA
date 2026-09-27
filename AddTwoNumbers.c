/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* solve(struct ListNode* l1, struct ListNode* l2, int carry){
    if (l1 == NULL && l2 == NULL && carry == 0){
        return NULL;
    }

    int sum = carry;
    if(l1!=NULL){sum+=l1->val;}
    if(l2!=NULL){sum+=l2->val;}

    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val=sum%10;
    node->next=solve((l1 ? l1->next : NULL ),(l2 ? l2->next : NULL),sum/10);

    return node; 
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return solve(l1,l2,0);
}
