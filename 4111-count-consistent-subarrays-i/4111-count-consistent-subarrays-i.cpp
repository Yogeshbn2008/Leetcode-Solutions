class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        if(n == 1)return 1;
        for(int i =0;i<n;i++){
            int mini = nums[i];
            int ans = nums[i];
            for(int j =i;j<n;j++){
                mini = min(mini,nums[j]);
                ans &= nums[j];
                if(mini == ans)cnt++;
            }
        }
        return cnt;
    }
};