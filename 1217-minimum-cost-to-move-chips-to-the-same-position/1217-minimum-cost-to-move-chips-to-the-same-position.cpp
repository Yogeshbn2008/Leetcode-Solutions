class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd =0;
        int even =0;
        for(int i : position){
            if(i%2){
                odd ++;
            }else{
                even ++;
            }
        }
        return min(odd,even);
        // return *min_element(position.begin(),position.end());
    }
};