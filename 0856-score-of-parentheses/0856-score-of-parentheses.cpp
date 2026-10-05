class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans =0;
        stack<int>st;
        st.push(0);
        for(char c : s){
            if(c == '(')st.push(0);
            else{
                int cur = st.top();
                st.pop();

                st.top() += max(1,2*cur);
            }
        }
       return  st.top();
    }
};