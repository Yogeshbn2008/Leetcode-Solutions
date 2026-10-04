class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>>dp(r,vector<int>(c,0));
        // for(int i = 0;i<r;i++){
        //     for(int j =0;j<c;j++){
        //         if(i == 0 && j ==0)dp[i][j] = matrix[i][j];
        //         else{
        //             int up = matrix[i][j];
        //             int le = matrix[i][j];
        //             if(i>0){
        //                 up += dp[i-1][j];
        //             }else{
        //                 up += 1e9;
        //             }

        //             if(j>0){
        //                 le += dp[i][j-1];
        //             }else{
        //                 le += 1e9;
        //             }
        //         dp[i][j] = min(le,up);

        //         }
        //     }
        // }
        // return dp[r-1][c-1];
        for(int i = 0;i<c;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1;i<r;i++){
            for(int j = 0;j<c;j++){
                int l = 1e9;
                int r = 1e9;
                int up = dp[i-1][j];
                if(j>0)l = dp[i-1][j-1];
                if(j<c-1)r = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min({up,l,r});

            }
        }
        return *min_element(dp[r-1].begin(),dp[r-1].end());
    }
};