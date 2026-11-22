class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        vector<string> ans;
        int n = rain.size();
        int alice = 0, bob = 0;

        for(int i = 0; i < n; i++) {
            if(rain[i] == 0) {
                ans.push_back("None");
            }
            else {
                bool a = (i != n-1 && rain[i+1] == 1);

                if(a && alice <= bob) {
                    ans.push_back("Alice");
                    alice++;
                }
                else {
                    ans.push_back("Bob");
                    bob++;
                }
            }
        }
        return ans;
    }
};