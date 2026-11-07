class Solution {
public:
    long long countValidSubstrings(string s) {
        long long total = 0;
        int last_abc = -1;

        for (int r = 0; r < (int)s.size(); r++) {
            if (r >= 2 && s[r-2] == 'a' && s[r-1] == 'b' && s[r] == 'c')
                last_abc = r;
            int invalid = max(0, last_abc - 1);
            total += (r + 1) - invalid;
        }

        return total;
    }
};