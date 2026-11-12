class Solution {
public:
    vector<vector<int>> dp;

    int superEggDrop(int k, int n) {
        dp.assign(k + 1, vector<int>(n + 1, -1));
        return solve(k, n);
    }

    int solve(int k, int n) {
        if (n == 0 || n == 1) return n;
        if (k == 1) return n;

        if (dp[k][n] != -1)
            return dp[k][n];

        int low = 1, high = n;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int eggBreaks = solve(k - 1, mid - 1);
            int eggSurvives = solve(k, n - mid);

            ans = min(ans, 1 + max(eggBreaks, eggSurvives));

            if (eggBreaks > eggSurvives) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return dp[k][n] = ans;
    }
};