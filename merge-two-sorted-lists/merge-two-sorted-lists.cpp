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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dum = new ListNode(-1);
        ListNode* root = dum;
        ListNode* con =dum;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 == NULL && l2 == NULL) return NULL;
        while(l1 != NULL && l2 != NULL) {
            if(l1 -> val >= l2 -> val) {
                ListNode* temp = new ListNode(l2 -> val);
                con -> next = temp;
                con = temp;
                l2 = l2 -> next;
            }
            if(l1 != NULL && l2 != NULL) {
                if(l1 -> val < l2 -> val){
                ListNode* temp = new ListNode(l1 -> val);
                con -> next = temp;
                con = temp;
                l1 = l1 -> next;
            }
            if(l1 == NULL && l2 != NULL) {
                while(l2 != NULL) {
                    ListNode* temp = new ListNode(l2 -> val);
                    con -> next = temp;
                    con = temp;
                    l2 = l2 -> next;
                }
            }
            }
            if(l1 != NULL && l2 == NULL) {
                while(l1 != NULL) {
                    ListNode* temp = new ListNode(l1 -> val);
                    con -> next = temp;
                    con = temp;
                    l1 = l1 -> next;
                }
            }
            
        }
        return root -> next;
    }
};