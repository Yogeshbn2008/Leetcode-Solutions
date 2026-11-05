class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = n-1;
        set<float>st;
        while(l<r){
            int x = nums[l];
            int y = nums[r];
            st.insert((x+y)/2.0);
            l++;
            r--;
        }
        return st.size();
    }
};