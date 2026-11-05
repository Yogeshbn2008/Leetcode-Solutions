class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            ans.push_back((nums[l]+nums[r])/2.0);
            r--;
            l++;
        }
        return *min_element(ans.begin(),ans.end());
    }
};