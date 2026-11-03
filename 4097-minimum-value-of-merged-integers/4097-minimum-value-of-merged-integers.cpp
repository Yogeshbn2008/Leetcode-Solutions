class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0;i<n-1;i+=2){
            int x = nums[i];
            int y = nums[i+1];
            string a = to_string(x)+to_string(y);
            ans.push_back(stoi(a));
        }
        return *min_element(ans.begin(),ans.end());
    }
};