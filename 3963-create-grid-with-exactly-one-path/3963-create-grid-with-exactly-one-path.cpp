class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        vector<vector<string>> temp(m, vector<string>(n, "#"));
        for(int j=0;j<n;j++){
            temp[0][j]='.';
        }
        for(int i=0;i<m;i++){
            temp[i][n-1]='.';
        }
        for(int i=0;i<m;i++){
            string v="";
            for(int j=0;j<n;j++){
                v+=temp[i][j];
            }
            ans.push_back(v);
        }
        return ans;
    }
};