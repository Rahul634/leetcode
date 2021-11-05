class Solution {
public:
    void findans(vector<int>candidates, int target, vector<int> curr, vector<vector<int>>&ans, int itr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i=itr; i<candidates.size(); i++){
            if(i > itr && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            int remain = target - candidates[i];
            curr.push_back(candidates[i]);
            findans(candidates, remain, curr, ans, i+1);
            curr.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        findans(candidates, target, curr, ans, 0);
        return ans;
    }
};