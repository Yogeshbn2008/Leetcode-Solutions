// class Solution {
// public:
//     string digitSum(string s, int k) {
//         int n = s.size();
//         int x = 101;
//         while(x>k){
//          string temp = "";
//             for(char c =0;c<n;c+=k){
//                 int sum =0;
//                 for(char i = c;c<k && c<n;c++){
//                     sum += s[i];
//                 }
//                 temp += to_string(sum);

//             }
//             x = temp.size();
//             s = temp;
//         }
        
//         return s;
//     }
// };
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            int n = s.size();
            string temp = "";
            for (int c = 0; c < n; c += k) {
                int sum = 0;
                for (int i = c; i < c + k && i < n; i++) {
                    sum += s[i] - '0';
                }
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;
    }
};   