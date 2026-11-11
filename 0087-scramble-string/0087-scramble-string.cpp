class Solution {
public:
    unordered_map<string, bool> mp;

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }

    bool solve(string a, string b) {

        if (a == b) return true;

        if (a.length() != b.length()) return false;

        if (a.length() <= 1) return false;

        string key = a + "_" + b;

        if (mp.find(key) != mp.end()) {
            return mp[key];
        }

        int n = a.length();
        bool flag = false;

        for (int i = 1; i < n; i++) {

            // Swapped condition
            bool swapped =
                solve(a.substr(0, i), b.substr(n - i, i)) &&
                solve(a.substr(i, n - i), b.substr(0, n - i));

            // Not swapped condition
            bool notSwapped =
                solve(a.substr(0, i), b.substr(0, i)) &&
                solve(a.substr(i, n - i), b.substr(i, n - i));

            if (swapped || notSwapped) {
                flag = true;
                break;
            }
        }

        return mp[key] = flag;
    }
};