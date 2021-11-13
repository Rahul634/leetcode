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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* temp=head;
        int len = 0;
        while(temp -> next != NULL) {
            temp = temp -> next;
            len ++;
        }
        len++;
        temp -> next = head;
        int rotateno = len-(k%len);
        temp = head;
        while(rotateno > 1) {
            temp = temp -> next;
            rotateno --;
        }
        ListNode* root=temp -> next;
        temp -> next = NULL;
        return root;
    }
};