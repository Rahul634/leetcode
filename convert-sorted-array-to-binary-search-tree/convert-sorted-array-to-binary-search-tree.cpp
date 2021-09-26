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
    TreeNode* checkans(vector<int> &nums, int start, int end){
        TreeNode* root;
        if(start > end){
            return nullptr;
        }
        if(start <= end){
            int mid = start + (end - start)/2 ;
            root = new TreeNode(nums[mid]);
            root -> left = checkans(nums, start, mid-1);
            root -> right = checkans(nums, mid+1, end);           
        }
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int end = nums.size();
        return checkans(nums, 0, end-1);
    }
};