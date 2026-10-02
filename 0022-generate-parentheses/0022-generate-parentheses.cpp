class Solution {
public:
    vector<string>ans;
    void bt(string curr , int op , int cl , int n ){
    if(curr.length() == 2*n){
        ans.push_back(curr);
        return;
    }if(op<n) bt(curr+'(' , op+1,cl,n );
    if(cl<op) bt(curr + ')' , op , cl+1, n);
}
    vector<string> generateParenthesis(int n) {
        bt("",0,0,n);
        return ans;

    }
};