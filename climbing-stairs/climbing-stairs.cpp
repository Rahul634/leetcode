
class Solution {
public:
    int clingstair(int n, unordered_map<int, int> &memo){
        if(n < 4) return n;
        if(memo[n]!=0) return memo[n];
        memo[n] = clingstair(n-1, memo) + clingstair(n-2, memo); 
        return memo[n];
    }
    int climbStairs(int n) {
        unordered_map<int, int>memo;
        return clingstair(n, memo);
    }
};