// class Solution {
// public:

//  vector<string> ans;

//     void solve(string &s, int i, string cur) {
//         if(i == s.size()) {
//             // check whether cur is valid
//             int balance = 0;

//             for(char ch : cur) {
//                 if(ch == '(') balance++;
//                 else if(ch == ')') balance--;

//                 if(balance < 0)
//                     return;
//             }

//             if(balance == 0)
//                 ans.push_back(cur);

//             return;
//         }

//         if(s[i] == '(' || s[i] == ')') {
//             // keep
//             solve(s, i + 1, cur + s[i]);

//             // remove
//             solve(s, i + 1, cur);
//         }
//         else {
//             // letter
//             solve(s, i + 1, cur + s[i]);
//         }
//     }
//     vector<string> removeInvalidParentheses(string s) {
//         solve(s, 0, "");
//         return ans;
//     }
// };
class Solution {
public:

    set<string> st;

    void solve(string &s, int i, string cur,
               int leftRemove, int rightRemove, int balance) {

        if(i == s.size()) {

            if(leftRemove == 0 && rightRemove == 0 && balance == 0)
                st.insert(cur);

            return;
        }

        // '('
        if(s[i] == '(') {

            // Remove '('
            if(leftRemove > 0) {
                solve(s, i + 1, cur,
                      leftRemove - 1, rightRemove, balance);
            }

            // Keep '('
            solve(s, i + 1, cur + '(',
                  leftRemove, rightRemove, balance + 1);
        }

        // ')'
        else if(s[i] == ')') {

            // Remove ')'
            if(rightRemove > 0) {
                solve(s, i + 1, cur,
                      leftRemove, rightRemove - 1, balance);
            }

            // Keep ')' only if there is '(' available
            if(balance > 0) {
                solve(s, i + 1, cur + ')',
                      leftRemove, rightRemove, balance - 1);
            }
        }

        // Letter
        else {

            solve(s, i + 1, cur + s[i],
                  leftRemove, rightRemove, balance);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        st.clear();

        int left = 0;
        int right = 0;

        // Find minimum number of removals
        for(char ch : s) {

            if(ch == '(') {
                left++;
            }
            else if(ch == ')') {

                if(left > 0)
                    left--;
                else
                    right++;
            }
        }

        solve(s, 0, "", left, right, 0);

        return vector<string>(st.begin(), st.end());
    }
};
// class Solution {
// public:

//     bool valid(string s) {
//         int balance = 0;

//         for(char ch : s) {
//             if(ch == '(')
//                 balance++;
//             else if(ch == ')')
//                 balance--;

//             if(balance < 0)
//                 return false;
//         }

//         return balance == 0;
//     }

//     vector<string> removeInvalidParentheses(string s) {

//         set<string> st;

//         // Try removing only ONE parenthesis
//         for(int i = 0; i < s.size(); i++) {

//             if(s[i] != '(' && s[i] != ')')
//                 continue;

//             string t = s.substr(0, i) + s.substr(i + 1);

//             if(valid(t))
//                 st.insert(t);
//         }
//         if (st.empty())return {""};
//         return vector<string>(st.begin(), st.end());
//     }
// };