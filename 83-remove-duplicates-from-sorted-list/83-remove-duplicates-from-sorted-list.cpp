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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* prev = dummy, *curr = head;
        while(curr != NULL) {
            if(prev -> val != curr -> val) {
                prev -> next = curr;
                prev = curr;
                curr = curr -> next;
            }else {
                curr = curr -> next;
            }
        }
        if(prev -> next != curr) {
            prev -> next = NULL;
        }
        return head;
    }
};