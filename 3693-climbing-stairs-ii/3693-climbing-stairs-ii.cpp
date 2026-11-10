
// class Solution {
// public:
//     int solve(int i, vector<int>& costs) {
//         if(i == 0) return 0;

//         int ans = INT_MAX;

//         for(int j = 1; j <= 3; j++) {
//             if(i - j >= 0) {
//                 ans = min(ans, solve(i-j, costs)
//                     + costs[i-1] + j*j);
//             }
//         }

//         return ans;
//     }

//     int climbStairs(int n, vector<int>& costs) {
//         return solve(n, costs);
//     }
// };

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                if(i-j >= 0) {
                    dp[i] = min(dp[i],
                        dp[i-j] + costs[i-1] + j*j);
                }
            }
        }

        return dp[n];
    }
};

