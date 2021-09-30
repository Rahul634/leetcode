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
    void inorder(TreeNode* root, int k, vector<int> &in){
        if(root == NULL) return ;
        inorder(root -> left, k, in);
        in.push_back(root -> val);
        inorder(root -> right, k, in);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int curr= INT_MAX;
        vector<int> in;
        inorder(root, k, in);
        return in[k-1];
    }
};