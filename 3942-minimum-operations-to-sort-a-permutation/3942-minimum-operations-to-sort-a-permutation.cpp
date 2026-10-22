// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         queue<pair<vector<int>, int>> q;
//         set<vector<int>> vis;

//         q.push({nums, 0});
//         vis.insert(nums);

//         while (!q.empty()) {
//             auto [a, steps] = q.front();
//             q.pop();

//             if (is_sorted(a.begin(), a.end()))
//                 return steps;

//             // Operation 1: Reverse
//             vector<int> b = a;
//             reverse(b.begin(), b.end());

//             if (!vis.count(b)) {
//                 vis.insert(b);
//                 q.push({b, steps + 1});
//             }

//             // Operation 2: Left rotate by one
//             b = a;
//             rotate(b.begin(), b.begin() + 1, b.end());

//             if (!vis.count(b)) {
//                 vis.insert(b);
//                 q.push({b, steps + 1});
//             }
//         }

//         return -1;
//     }
// };
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto check = [&](int step) {
            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;

                if (nums[prev] > nums[curr])
                    return false;
            }
            return true;
        };

        int ans = INT_MAX;

        if (check(1)) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        if (check(-1)) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};