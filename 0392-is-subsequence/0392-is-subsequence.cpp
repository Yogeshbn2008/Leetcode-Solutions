class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int j =0;
        int n = s.size();
        int m = t.size();
        // while(i<n && j<m){
            
        // }
        for(int i =0;i<n;i++){
            char c = s[i];
            while(j<m && t[j] != c){
                j++;
            }
            if(j == m)return false;
            j++;
        }return true;
    }
};