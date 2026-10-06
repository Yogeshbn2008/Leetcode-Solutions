class Solution {
public:
    int splitNum(int num) {
        string n1 = "";
        string n2 = "";
        // set<char>st;
        string nums = to_string(num);
    sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            if(i%2 == 0){
                n1 += nums[i];
            }else{
                n2 += nums[i];
            }
        }
        // for(char c : nums){
        //     st.insert(c);
        // }
        // int cnt =0;
        // for(auto &it :st){
        //     cnt++;
        //     if(cnt%2){
        //         n1 += it;
        //     }else{
        //         n2 += it;
        //     }
        // }
        return stoi(n1)+stoi(n2);

    }
};