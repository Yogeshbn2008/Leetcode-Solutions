class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        // int ans1 = 1;
        // int ans2 = 1;
        // for(int i =0;i<n;i++){
        //     bool a1 = true;
        //     bool a2 = true;
        //     for(int j =i;j<n;j++){
        //         if(i>0){
        //             if(nums[i]>nums[i-1] && a1){
                        
        //                 ans1 = max(ans1,j-i+1);
        //              }else{
        //                 a1 = false;
        //              }
        //               if(nums[i]<nums[i-1] && a2){
        //                 ans2 = max(ans2,j-i+1);

        //               }else{
        //                 a2 = false;
        //               }
        //         }
        //     }
        // }
        // return max(ans1,ans2);
        int ans = 1 ;
        // for(int i =0;i<n;i++){
        //     int len = 1;
        //     for(int j = i+1;j<n;j++){
        //         if(nums[j] == nums[j-1])break;
        //         if((j == i+1) || (nums[j] > nums[j-1]) == (nums[i]<nums[i+1])){
        //             len++;
        //             ans = max(len,ans);
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return ans;
        int inc = 1;
        int dec = 1;
        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1]){
                inc++;
                dec = 1;
            }else if(nums[i]<nums[i-1]){
                dec++;
                inc = 1;
            }else{
                inc = dec = 1;
            }
            ans = max(ans,max(inc,dec));
        }
        return ans;
    }
};