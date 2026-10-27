class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>>ans(m,vector<char>(n,'#'));
        
        for(int i=0;i<n;i++){
            ans[0][i] = '.';
        }
        for(int j = 1;j<m;j++){
            ans[j][n-1] = '.';
        }
        vector<string>res;
        for(int i =0;i<m;i++){
            res.push_back(string(ans[i].begin(),ans[i].end()));
        }
        return res;
        // ans[0][m-1] = "#";
        // ans[1][0] = "#";
        // for(int i =2;i<m;i++){
        //     for(int j = 0;j<n-1;j++){
        //         ans[i][j] = "#";
        //     }
        // }
        // vector<string>res;

        // return ans;
    }
};