//   class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         long long k = (long long)k1 + k2;
//         int n = nums1.size();
//         vector<int> diff(n);
//         int mx = 0;

//         for(int i = 0; i < n; i++) {
//             diff[i] = abs(nums1[i] - nums2[i]);
//             mx = max(mx, diff[i]);
//         }

//         long long sum = 0;
//         for(int d : diff) sum += d;

//         if(k >= sum) return 0;

//         int l = 0, r = mx;

//         while(l < r) {
//             int mid = l + (r - l) / 2;
//             long long need = 0;

//             for(int d : diff)
//                 if(d > mid) need += d - mid;

//             if(need <= k) r = mid;
//             else l = mid + 1;
//         }

//         long long used = 0, ans = 0;

//         for(int d : diff) {
//             if(d > l) {
//                 used += d - l;
//                 d = l;
//             }
//             ans += 1LL * d * d;
//         }

//         long long remaining = k - used;

//         for(int i = 0; i < n && remaining > 0; i++) {
//             if(diff[i] == l && l > 0) {
//                 ans -= 1LL * l * l;
//                 ans += 1LL * (l - 1) * (l - 1);
//                 remaining--;
//             }
//         }

//         return ans;
//     }
// };
   class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<int> freq(100001, 0);
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            mx = max(mx, d);
        }

        for (int d = mx; d > 0 && k > 0; d--) {
            long long move = min(k, 1LL * freq[d]);
            freq[d] -= move;
            freq[d - 1] += move;
            k -= move;
        }

        long long ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};