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
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* pre = new TreeNode(INT_MIN);
public:
    void swap() {
        int temp;
        temp = first -> val;
        first -> val = second -> val;
        second -> val = temp;
    }
    void inorder(TreeNode* root){
        if(root == NULL) return;
        if(root != NULL){
            inorder(root -> left);
            if(first == NULL && pre -> val > root -> val){
                first = pre;
            }
            if(first != NULL && pre -> val > root -> val){
                second = root;
            }
            pre = root;
            inorder(root -> right);
        }
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        cout << first -> val << " " << second -> val;
        swap();
    }
};