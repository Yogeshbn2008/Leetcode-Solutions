// class Solution {
// public:
//     vector<vector<int>>dp;
//     int solve(string &s,int i,int j){
//         if(i>=j)return 0;
//         if(ispalindrome(s,i,j))return 0;
//         int mn = INT_MAX;
//         if(dp[i][j] != -1)return dp[i][j];
//         for(int k = i;k<=j-1;k++){
//             int par = 1+solve(s,i,k)+solve(s,k+1,j);
//             mn = min(mn,par);
//         }
//         return mn;
//     }
//     bool ispalindrome(string &s,int left,int right){
//         while (left < right) {
//         if (s[left] != s[right]) {
//             return false;
//         }
//         left++;
//         right--;
//     }
//     return true;
//     }
//     int minCut(string s) {
//         int n = s.size();
//         dp.assign(n+1,vector<int>(n+1,-1));
//         if(n == 2){
//             if(ispalindrome(s,0,1))return 0;
//             return 1;
//             }
//         return solve(s,1,n-1);
//     }
// };
class Solution {
public:
    vector<vector<int>> dp;

    bool ispalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    int solve(string &s, int i, int j) {
        if (i >= j || ispalindrome(s, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mn = INT_MAX;

        for (int k = i; k < j; k++) {
            if (ispalindrome(s, i, k)) {
                int par = 1 + solve(s, k + 1, j);
                mn = min(mn, par);
            }
        }

        return dp[i][j] = mn;
    }

    int minCut(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        return solve(s, 0, n - 1);
    }
};