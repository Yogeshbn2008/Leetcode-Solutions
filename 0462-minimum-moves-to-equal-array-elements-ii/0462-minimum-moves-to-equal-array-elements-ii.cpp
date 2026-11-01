class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int  mid = nums[n/2];
        if(n%2 == 0){
            mid += nums[n/2 - 1];
            mid /= 2;
        }
        int ans = 0;
        for(int i:nums){
            ans += abs(i-mid);
        }
        return ans;
    }
};