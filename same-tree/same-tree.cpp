/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool ans = true;
public:
    void checktree(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)
            return ;
        if(p==NULL || q==NULL){
            ans = false;
            return;
        }
        if(p!=NULL && q!=NULL){
            checktree(p -> left, q-> left);
            if(p -> val != q-> val){
                ans = false;
                return ;
            }
            checktree(p -> right, q->right);
        }
        return ;
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        checktree(p, q);
        return ans;
    }
};