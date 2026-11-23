class Solution {
public:
    int minRange(int a, int b, int c) {
        int maxi = max({a,b,c});
        int mini = min({a,b,c});
        int ans = maxi - mini;
         maxi = a+b+c - maxi;
            ans = min(ans,maxi-mini);
            return ans;
    }
};