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
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* fast = dummy, *slow = dummy;
        while(fast!=NULL && n--) {
            fast = fast -> next;
        }
        if(fast == NULL) return head;
        else {
            while(fast -> next != NULL) {
                fast = fast -> next;
                slow = slow -> next;
            }
            slow -> next = slow -> next -> next;
        }
        return dummy -> next;
    }
};