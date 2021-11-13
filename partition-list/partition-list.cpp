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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy_s = new ListNode(-1);
        ListNode* dummy_b = new ListNode(-1);
        ListNode* small = dummy_s, *big = dummy_b;
        while(head != NULL) {
            if(head -> val < x) {
                ListNode* temp = new ListNode(head -> val);
                dummy_s -> next = temp;
                dummy_s = temp;
                head = head -> next;
            }else if(head -> val >= x) {
                ListNode* temp = new ListNode(head -> val);
                dummy_b -> next = temp;
                dummy_b = temp;
                head = head -> next;
            }
        }
        dummy_s -> next = big -> next;
        return small -> next;
    }
};