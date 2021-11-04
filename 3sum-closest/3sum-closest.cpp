class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
       sort(nums.begin(),nums.end());
        int ans=INT_MAX,closetsum=0;
        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;
            while(j<k){
                int temp=abs(nums[i]+nums[j]+nums[k]-target);
            if(temp==0)return target;
            if(temp<ans)
            {
                ans=temp;
                closetsum=nums[i]+nums[j]+nums[k];
            }
            if(nums[i]+nums[j]+nums[k]>target)
                k--;
            else
                j++;
        }
        }
        return closetsum;
    }
};