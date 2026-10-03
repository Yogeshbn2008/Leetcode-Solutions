class Solution {
public:
    set<vector<int>>st;
        
    void solve(vector<int>&nums , int i,vector<int>&v){
        if(v.size()>=2){
            st.insert(v);
        }
        for(int j = i;j<nums.size();j++){
            if(v.empty() || nums[j]>=v.back()){
                v.push_back(nums[j]);
                solve(nums,j+1,v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // vector<vector<int>> ans;
        // int n = num.size();
        // for(int i=0;i<n-1;i++){
        //     for(int j = i+1;j<n;j++){
        //         if(nums[j]>nums[i]){

        //         }
        //     }
        // }
        vector<int>v;
        solve(nums,0,v);
        return vector<vector<int>>(st.begin(),st.end());

    }
};