class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_r=0, max_r=0, count=0;
        for(int i=0; i<nums.size()-1; i++){
            max_r = max(max_r, i+nums[i]);
            if(i == cur_r){
                count++;
                cur_r = max_r;
            }
        }
        return count;
    }
};