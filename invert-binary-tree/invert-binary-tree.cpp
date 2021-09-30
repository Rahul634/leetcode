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
public:
    TreeNode* inverttree(TreeNode* root){
        if(root == NULL) return NULL;
        inverttree(root -> left);
        inverttree(root -> right);
        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return inverttree(root);
    }
};