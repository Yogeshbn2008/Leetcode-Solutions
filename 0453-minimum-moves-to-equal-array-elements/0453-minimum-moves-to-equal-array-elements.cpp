class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
       int ans = 0;
       int mini = *min_element(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            ans += nums[i] - mini;
        }
        return ans;
        
    }
};