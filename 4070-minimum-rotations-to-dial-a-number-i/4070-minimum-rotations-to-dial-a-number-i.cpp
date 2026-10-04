class Solution {
public:
    int minRotations(string s) {
        int ans =0;
        int prev = '0';
        for(char c : s){
            ans += min(abs(prev-c) , 10 - abs(prev-c));
            prev = c;
        }return ans;
    }
};