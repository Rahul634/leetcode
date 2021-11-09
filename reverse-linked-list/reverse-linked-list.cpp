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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* first=NULL, *second=NULL, *last = head;
        while(last !=NULL){
            first = second;
            second = last;
            last = last -> next;
            second -> next = first;
        }
        second -> next = first;
        head = second;
        return head;
    }
};