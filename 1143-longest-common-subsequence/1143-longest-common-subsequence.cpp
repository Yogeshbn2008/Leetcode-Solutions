class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return func(text1,text2,n,m,dp);
        for(int i = 1;i<n+1;i++){
            for(int j = 1;j<m+1;j++){
                if(text1[i-1] == text2[j-1]){
                     dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    
    return dp[n][m];
    // int func(string &t1,string &t2,int n , int m,vector<vector<int>>&dp ){
    //     if(n == 0 || m == 0)return 0;
    //     if(dp[n][m] != -1)return dp[n][m];
    //     if(t1[n-1] == t2[m-1]){
    //         return dp[n][m] = 1+func(t1,t2,n-1,m-1,dp);
    //     }else{
    //         return dp[n][m] = max(func(t1,t2,n,m-1,dp),func(t1,t2,n-1,m,dp));
    //     }
    }
};