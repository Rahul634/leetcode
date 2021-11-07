class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();
        if(obstacleGrid[M-1][N-1] == 1)
            return 0;
        vector<vector<int>> sol(M, vector<int>(N, 0));
        for(int i = 0; i < M; ++i) {
            if(i != 0) {
                sol[i][0] = obstacleGrid[i][0] != 1 ? sol[i-1][0] : 0;
            } else {
                sol[i][0] = obstacleGrid[i][0] != 1 ? 1 : 0;                
            }
        }
        for(int i = 0; i < N; ++i) {
            if(i != 0) {
                sol[0][i] = obstacleGrid[0][i] != 1 ? sol[0][i-1] : 0;
            } else {
                sol[0][i] = obstacleGrid[0][i] != 1 ? 1 : 0;            
            }
        }
        for(int i = 1; i < M; ++i) {
            for(int j = 1; j < N; ++j) {
                if(obstacleGrid[i][j] != 1) {
                    sol[i][j] = sol[i-1][j] + sol[i][j-1];
                } else
                    sol[i][j] = 0;
            }            
        }
        return sol[M-1][N-1];
    }
};