/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   if(root == NULL) return ; 
    
    if(root->left == NULL and root->right == NULL){
        now = now + root->val ; 
        res.push_back(root->val) ; 
        if(now == sum){
            ans.push_back(res);
        }
        now = now - root->val ; 
        res.pop_back(); 
        return ; 
    }
    res.push_back(root->val) ; 
    now = now + root->val ; 
    solve(root->left , now , sum , res) ; 
    solve(root->right , now , sum , res) ; 
    now = now - root->val ; 
    res.pop_back() ; 
    return ; 
 * };
 */
class Solution {
public:
    void findPath(TreeNode* root, int target, vector<int> curr, vector<vector<int>> &ans, int now){
        if(root == NULL) return;
        if(root -> right == NULL && root -> left == NULL){
            now = now + root -> val;
            curr.push_back(root -> val);
            if(now == target){
                ans.push_back(curr);
            }
            curr.pop_back();
            now = now - root -> val;
            return;
        }
        curr.push_back(root -> val);
        now = now + root -> val;
        findPath(root -> left, target, curr, ans, now);
        findPath(root -> right, target, curr, ans, now);
        now = now - root -> val;
        curr.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        vector<vector<int>> ans;
        findPath(root, targetSum, curr, ans, 0);
        return ans;
    }
};