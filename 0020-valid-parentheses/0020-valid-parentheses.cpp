class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 )return false;
        stack<char>st;
        unordered_map<char,char>mp={
            {')' , '('},
            {'}' , '{'},
            {']' , '['},
        };
        for(char c:s){
            if(mp.count(c)){
                if(st.empty() || st.top() != mp[c]){
                    return false;
                }
                st.pop();
            }else{
                st.push(c);
            }
        }
        return st.empty();
    }
};