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
class comparator {
    public:
    bool operator()(ListNode* a, ListNode* b){ return (a->val > b->val);}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 1->4->5
        // 1->3->4
        // 2->6
        priority_queue<ListNode*, vector<ListNode*>, comparator>pq;
        int n = lists.size();
        
        for(int i=0; i<n; i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        while(!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            prev -> next = temp;
            prev = prev -> next;
            if(temp -> next != NULL) {
                pq.push(temp->next);
            }
        }
        return dummy -> next;
    }
};