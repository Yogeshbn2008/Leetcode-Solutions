class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // sort(nums.begin(),nums.end(),[](int a , int b){
        //     return abs(a)>abs(b);});
        // int n = nums.size();
        // long long ans = 0;
        
        // for(int i =0;i<n;i++){
        //     if(i%2 == 0){
        //         // pos = (pos + 1LL*nums[i]*nums[i]);
        //         ans += nums[i]*nums[i];
        //     }else{
        //         // neg = (neg + 1LL*nums[i]*nums[i]);
        //         ans -= nums[i]*nums[i];
        //     }
        // }
        // // return pos-neg;
        // return ans;
        vector<int>sq;
        for(int i : nums){
            sq.push_back(1LL*i*i);
        }
        sort(sq.begin(),sq.end());
        int n = sq.size();
        long long ans = 0;
        for(int i =0;i<n;i++){
            if(i<(n)/2){
                ans -= sq[i];
            }else{
                ans += sq[i];
            }
        }
       return ans;
    }
};