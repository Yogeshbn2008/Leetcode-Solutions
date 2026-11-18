class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int cnt =0;
        // for(char i : s){
        //     if(i == '1')cnt++;
        // }
        for(int i = 0;i<n;i+=2){
            if(s[i] == s[i+1])continue;
            cnt++;
        }
        return cnt;
    }
};