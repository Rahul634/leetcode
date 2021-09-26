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
    bool valid(TreeNode * root, int min,int max,bool checkl, bool checkr)
{
    if(root==NULL){
        return true;
    }
    
    if(checkl and (root->val<=min)){
        return false;
    }
    
    if(checkr and (root->val>=max)){
        return false;
    }
    
    bool p1 = valid(root->left,min,root->val,checkl,true);
    bool p2 = valid(root->right,root->val,max,true,checkr);
    
    return p1&&p2;
}

bool isValidBST(TreeNode* root) {
    return valid(root,INT_MIN,INT_MAX,false,false);
}
};
