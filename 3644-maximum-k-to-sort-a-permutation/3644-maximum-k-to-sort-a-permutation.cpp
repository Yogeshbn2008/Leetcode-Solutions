class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int ans = -1;
        for(int i =0;i<n;i++){
            if(nums[i] != i){
                ans &= nums[i];
            }
        }
        return max(0,ans);

        // if (is_sorted(nums.begin(), nums.end()))
        //     return 0;

        // for (int k = n - 1; k >= 0; k--) {
        //     queue<vector<int>> q;
        //     set<vector<int>> vis;

        //     q.push(nums);
        //     vis.insert(nums);

        //     while (!q.empty()) {
        //         vector<int> a = q.front();
        //         q.pop();

        //         if (is_sorted(a.begin(), a.end()))
        //             return k;

        //         for (int i = 0; i < n; i++) {
        //             for (int j = i + 1; j < n; j++) {
        //                 if ((a[i] & a[j]) == k) {
        //                     swap(a[i], a[j]);

        //                     if (!vis.count(a)) {
        //                         vis.insert(a);
        //                         q.push(a);
        //                     }

        //                     swap(a[i], a[j]);
        //                 }
        //             }
        //         }
        //     }
        // }

        // return 0;
    }
};