class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0, end = height.size()-1;
        int ans = INT_MIN;
        while(start < end){
            int h = min(height[start], height[end]);
            int area = h*(end - start);
            ans = max(ans, area);
            if(h == height[start]){
                start ++;
            }else if(h == height[end]){
                end --;
            }else {
                start ++;
                end --;
            }
        }
        return ans;
    }
};