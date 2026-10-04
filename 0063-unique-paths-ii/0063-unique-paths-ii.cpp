class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int mod = (1e9+7);
        int c = obstacleGrid.size();
        int r = obstacleGrid[0].size();
        vector<vector<int>>dp(c,vector<int>(r,0));
        for(int i = 0;i<c;i++){
            for(int j = 0;j<r;j++){
                
                 if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if(i== 0 && j == 0){
                    dp[i][j] = 1;
                } 
                // if(i<0 || j<0)dp[i][j] = 0;
                else{
                int up =0;int lt = 0;
                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    lt = dp[i][j-1];
                }
                dp[i][j] = (up+lt);
                }
            }
        }
        return dp[c-1][r-1];
    }
};