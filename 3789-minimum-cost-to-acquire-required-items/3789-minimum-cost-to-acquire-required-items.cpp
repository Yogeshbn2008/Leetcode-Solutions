class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1 == 0 && need2 == 0)return 0;
        int x = min(need1 , need2);
        int y = min(costBoth , cost1 + cost2);
        long long ans = 0;
        ans += 1LL*x*y;
        int a = need1 - x ;
        if(a){
            ans = ans + (a*1LL*(min(costBoth , cost1)));
        }
        int b = need2 - x;
        if(b){
            ans = ans + (b*1LL*(min(costBoth , cost2)));
        }
        return ans ;
    }
};