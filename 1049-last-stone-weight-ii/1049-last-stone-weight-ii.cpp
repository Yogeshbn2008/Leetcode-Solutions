class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(),stones.end(),0);
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i = 0;i<n+1;i++){
            for(int j = 0;j<sum+1;j++){
                if(j == 0){
                    dp[i][j] = true;
                    continue;
                }
                if(i>0){
                    if(stones[i-1]<=j){
                        dp[i][j] = dp[i-1][j-stones[i-1]] || dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        int mn = INT_MAX;
        for(int i =0;i<=sum/2;i++){
            if(dp[n][i]){
                mn = min(mn,sum-(2*i));
            }
        }
        return mn;
    }
};