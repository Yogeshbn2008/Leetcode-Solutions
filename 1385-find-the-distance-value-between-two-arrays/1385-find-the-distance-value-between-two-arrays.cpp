class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int a = arr1.size();
        int b = arr2.size();
        int ans = 0;
        for(int i =0;i<a;i++){
            bool is = true;
            for(int j = 0;j<b;j++){
                
                if(abs(arr1[i]-arr2[j])<=d)is = false;
                
            }
            if(is)ans++;
        }
        return ans;

    }
};