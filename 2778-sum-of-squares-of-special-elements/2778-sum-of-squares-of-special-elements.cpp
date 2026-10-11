class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
       int ans = 0;
        for(int i =1;i*i<=n;i++){
            if(n%i == 0){
            //     long p = nums[i];
            //    long  x = pow(p,2);
            // int p = nums[i-1];
            // int x = p*p;
            //     ans += x;
            ans += nums[i-1]*nums[i-1];
            if(i*i != n){
                ans += nums[n/i-1]*nums[n/i-1];
            }
            }
        }return ans;
    }
};