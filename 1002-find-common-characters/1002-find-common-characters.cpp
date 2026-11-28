class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        int n = words.size();

        unordered_map<char, int> mp;

        for(char c : words[0]){
            mp[c]++;
        }

        for(int i = 1; i < n; i++){
            unordered_map<char, int> temp;

            for(char c : words[i]){
                temp[c]++;
            }

            for(auto &it : mp){
                it.second = min(it.second, temp[it.first]);
            }
        }

        for(auto &it : mp){
            while(it.second--){
                ans.push_back(string(1, it.first));
            }
        }

        return ans;
    }
};