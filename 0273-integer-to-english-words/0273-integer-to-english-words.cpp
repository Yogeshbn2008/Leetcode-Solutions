class Solution {
    unordered_map<int, string> d = {
        {1,"One"}, {2,"Two"}, {3,"Three"}, {4,"Four"}, {5,"Five"},
        {6,"Six"}, {7,"Seven"}, {8,"Eight"}, {9,"Nine"}, {10,"Ten"},
        {11,"Eleven"}, {12,"Twelve"}, {13,"Thirteen"}, {14,"Fourteen"},
        {15,"Fifteen"}, {16,"Sixteen"}, {17,"Seventeen"}, {18,"Eighteen"},
        {19,"Nineteen"}, {20,"Twenty"}, {30,"Thirty"}, {40,"Forty"},
        {50,"Fifty"}, {60,"Sixty"}, {70,"Seventy"}, {80,"Eighty"}, {90,"Ninety"}
    };

    string helper(int num) {
        if (num == 0) return "";
        if (num < 20) return d[num];
        if (num < 100) {
            string res = d[num / 10 * 10];
            if (num % 10) res += " " + helper(num % 10);
            return res;
        }
        if (num < 1000) {
            string res = d[num / 100] + " Hundred";
            if (num % 100) res += " " + helper(num % 100);
            return res;
        }
        if (num < 1000000) {
            string res = helper(num / 1000) + " Thousand";
            if (num % 1000) res += " " + helper(num % 1000);
            return res;
        }
        if (num < 1000000000) {
            string res = helper(num / 1000000) + " Million";
            if (num % 1000000) res += " " + helper(num % 1000000);
            return res;
        }
        // Billion
        string res = helper(num / 1000000000) + " Billion";
        if (num % 1000000000) res += " " + helper(num % 1000000000);
        return res;
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num);
    }
};