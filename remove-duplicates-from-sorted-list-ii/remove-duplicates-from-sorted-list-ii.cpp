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
        if(head == NULL) return head;
        if(head -> next == NULL) return head;
        unordered_set<int> s;
        ListNode* temp = head;
        while(temp -> next != NULL) {
            if(temp -> val == temp -> next -> val){
                s.insert(temp -> val);
            }
            temp = temp -> next;
        }
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* dum = dummy -> next;
        ListNode* prev=dummy;
        while(dum != NULL) {
            if(s.find(dum -> val) != s.end()) {
                cout << "hello";
                prev -> next = dum -> next;
                dum = prev -> next;
            }else {
                prev = dum;
                dum = dum -> next;
            }
        }
        return dummy -> next;
    }
};