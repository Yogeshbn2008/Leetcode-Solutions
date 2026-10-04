class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int op = 0;
        int cl =0;
        int len = n-1;
        for(int i =0;i<=len;i++){
            if(s[i] == '('||s[i] == '*')op++;
            else op--;
            if(s[len-i] == ')'||s[len-i] == '*')cl++;
            else cl--;
            if(op<0 || cl<0)return false;
        }
        return true;
        // int mn =0;
        // int mx =0;
        // for(char c :s){
        //     if(c == '('){
        //         mn ++;
        //         mx ++;
        //     }else if(c == ')'){
        //         mn--;
        //         mx--;
        //     }else{
        //         mn--;
        //         mx++;
        //     }
        //     if(mn < 0) mn =0;
        //     if(mx <0)return false;

        // }return (mn==0);
    }
};
// if(n == 1)return false;
        // if(s == "()")return true;
        // int o =0;
        // int m =0;
        // int c =0;
        // for(char c : s){
        //     if(c == '(') o++;
        //     else if(c == ')') c++;
        //     else if(c == '*') m++;
        // }
        // if(o == c)return true;
        // if(o > c){
        //     if(o == c+m)return true;
        //     else return false;
        // }else if(c>o){
        //     if(c == o+m)return true;
        //     else return false;
        // }else return true;