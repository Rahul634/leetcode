/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* findAns(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if(root -> val == p -> val || root -> val == q -> val){
            return root;
        }
        TreeNode* l = findAns(root -> left, p, q);
        TreeNode* r = findAns(root -> right, p, q);
        if(l && r) return root;
        if(!l && !r) return NULL;
        if(!l) return r;
        if(!r) return l;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findAns(root, p, q);
    }
};