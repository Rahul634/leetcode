class Solution {
public:
    int maxSubArray(vector<int>& vect) {    
        int n = vect.size();
        int curr = 0, prev = vect[0];
        for(int i = 0; i < n; i++){
            curr += vect[i];
            if(vect[i] > curr)
                curr = vect[i];
            if(curr > prev){
                prev = curr;
            }
        }
        return prev;
    }
};