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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        while(list1 != NULL && list2 != NULL) {
            if(list1 -> val < list2 -> val) {
                prev -> next = new ListNode(list1 -> val);
                list1 = list1 -> next;
            }else {
                prev -> next = new ListNode(list2 -> val);
                list2 = list2 -> next;
            }
            prev = prev -> next;
        }
        while(list1!=NULL) {
            prev -> next = new ListNode(list1 -> val);
            prev = prev -> next;
            list1 = list1 -> next;
        }
        while(list2!=NULL) {
            prev -> next = new ListNode(list2 -> val);
            prev = prev -> next;
            list2 = list2 -> next;
        }
        return dummy -> next;
    }
};