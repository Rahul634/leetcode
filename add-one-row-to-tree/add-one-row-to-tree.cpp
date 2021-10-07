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
    TreeNode* adding(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp -> left = root;
            temp -> right = NULL;
            return temp;
        }
        queue<TreeNode*> q;
        q.push(root);
        for(int i=1; i<depth-1; i++){
            int size = q.size();
           while(size--){
                TreeNode* temp = q.front();
            q.pop();
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
           }
            
        }
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            TreeNode* newnode1 = new TreeNode(val);
            TreeNode* newnode2 = new TreeNode(val);
            newnode1 -> left = p -> left;
            newnode1 -> right = NULL;
            p -> left = newnode1;
            
            newnode2 -> right = p -> right;
            newnode2 -> left = NULL;
            p -> right = newnode2;
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return adding(root, val, depth);
    }
};