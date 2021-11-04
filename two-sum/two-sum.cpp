class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int remainder = target - nums[i];
            if(mp.find(remainder) == mp.end()){
                mp[nums[i]] = i;
            }else {
                ans.push_back(mp[remainder]);
                ans.push_back(i);
            }
            }
           return ans;  
        }
   
    
};