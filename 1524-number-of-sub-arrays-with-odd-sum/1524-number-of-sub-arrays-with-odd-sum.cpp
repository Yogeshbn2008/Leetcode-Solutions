class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int ocnt = 0, ecnt = 1;
        int cnt = 0;
        int sum = 0;
        for (int x : arr) {
            sum = (sum + x) & 1;          // keep parity bounded
            if (sum) {
                cnt = (cnt + ecnt) % mod;
                ocnt++;
            } else {
                cnt = (cnt + ocnt) % mod;
                ecnt++;
            }
        }
        return cnt;
    }
};   