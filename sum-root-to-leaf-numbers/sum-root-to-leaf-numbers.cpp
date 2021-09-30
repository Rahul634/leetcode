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
    int checkleaf(TreeNode* root, int sum){
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL){
            sum = sum*10 + root -> val;
            return sum;
        }
        sum = sum*10 + root -> val;
        int l = checkleaf(root -> left, sum);
        int r = checkleaf(root -> right, sum);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return checkleaf(root, sum);
    }
};