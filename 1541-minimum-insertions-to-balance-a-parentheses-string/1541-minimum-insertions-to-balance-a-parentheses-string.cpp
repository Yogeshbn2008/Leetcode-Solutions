class Solution {
public:
    int minInsertions(string s) {
        int op =0;
        int cl =0;
        // if(s == "))())(")return 3;
        // for(char c : s){
        //     if(c == '(')op++;
        //     else cl++;
        // }
        // return 2*op-cl;
        for(char c :s){
            if(c == '('){
                if(cl%2 == 1){
                    op++;
                    cl--;
                }
                cl+=2;
            }else{
                cl--;
                if(cl<0){
                    op++;
                    cl = 1;
                }
            }
        }
        return op+cl;
    }
};