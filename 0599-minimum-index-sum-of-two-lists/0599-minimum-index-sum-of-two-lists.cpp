class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        // unordered_map<string,int>mp;
        // for(int i =0;i<list1.size();i++){
        //     mp[list1[i]] += i;
        // }
        // for(int i =0;i<list2.size();i++){
        //     mp[list2[i]] += i;
        // }
        // int mini = INT_MAX;
        // vector<string>ans;
        // for(int i =0;i<list1.size();i++){
        //     for(int j =0;j<list2.size();j++){
        //         if(list1[i] == list2[j]){
        //             if(i+j == mini){
        //                 ans.push_back(list1[i]);
                        
                       
        //             }else if(i+j < mini){
        //                 ans.clear();
        //                 mini = i+j;
        //                 ans.push_back(list1[i]);
                        
                        
        //             }
        //             break;
        //         }
        //     }
        // }
        // return ans;
         unordered_map<string, int> mp;

        // Store restaurant and its index from list1
        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }

        vector<string> ans;
        int mini = INT_MAX;

        // Search list2
        for (int j = 0; j < list2.size(); j++) {

            if (mp.find(list2[j]) != mp.end()) {

                int sum = mp[list2[j]] + j;

                if (sum < mini) {
                    mini = sum;
                    ans.clear();
                    ans.push_back(list2[j]);
                }
                else if (sum == mini) {
                    ans.push_back(list2[j]);
                }
            }
        }

        return ans;

    }
};