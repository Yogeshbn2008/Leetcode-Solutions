class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int cnt =0;
        int mini =0;
        for(char c : s){
            if(c == '(')cnt++;
            else {
                cnt>0?cnt--:mini++;
            }
        }
        return mini+cnt;
    }
};