class Solution {
public:
    int longestValidParentheses(string s) {
        int ans =0;
        int n = s.size();
        // if(n%2 == 1)return n-1;
        // for(int i=0;i<s.size();i++){
        //     if(i == 0 && s[i] == ')'){
        //         cnt--;
        //         continue;
        //     }
        //     else cnt++;
        // }
        // return cnt ;
        stack<int>st;
        st.push(-1);
        for(int i = 0;i<n;i++){
            if(s[i] == '(')st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ans = max(ans,i-st.top());
                }
            }
        }return ans;
    }
};