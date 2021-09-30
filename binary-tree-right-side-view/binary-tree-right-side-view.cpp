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
    void rightlevel(TreeNode* root, vector<int> &ans){
        if(root == NULL) return ;
        queue<TreeNode*> q1;
        q1.push(root);
        while(!q1.empty()){
            int size = q1.size();
            for(int i=0; i<size; i++){
                TreeNode* temp = q1.front();
                q1.pop();
                if(i == size-1){
                    ans.push_back(temp -> val);
                }
                if(temp -> left != NULL){
                    q1.push(temp -> left);
                }
                if(temp -> right != NULL){
                    q1.push(temp -> right);
                }
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightlevel(root, ans);
        return ans;
    }
};