class Solution {
public:
    void swp(vector<int> &nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    void permutations(vector<int> nums, vector<vector<int>> &ans, int itr){
        if(itr == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=itr; i<nums.size(); i++){
            if(s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            swp(nums, itr, i);
            permutations(nums, ans, itr+1);
            swp(nums, i, itr);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums, ans, 0);
        return ans;
    }
};