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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(1);
        temp -> next = head;
        ListNode* prev = temp, *last = temp;
        int i=1;
        while(i <= n){
            last = last -> next;
            i++;
        }
        while(last -> next != NULL){
            last = last -> next;
            prev = prev -> next;
        }
        prev -> next = prev -> next -> next;
        return temp -> next;
        
    }
};