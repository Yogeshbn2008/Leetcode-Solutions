class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum < abs(target) || (sum + target) % 2 != 0)
                   return 0;
        int subsum = (abs(target+sum))/2;
        int n = arr.size();
        int mod = 1000000007;
        vector<vector<int>>dp(n+1,vector<int>(subsum+1,0));
        for(int i=0;i<n+1;i++){
            for(int j = 0;j<subsum+1;j++){
                if(j == 0){
                    dp[i][j] = 1;
                }
                if(i>0){
                    if(arr[i-1]<=j){
                        dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j])%mod;
                    }else{
                        dp[i][j] = (dp[i-1][j])%mod;
                    }
                }
            }
        }
        return dp[n][subsum];
    }
};