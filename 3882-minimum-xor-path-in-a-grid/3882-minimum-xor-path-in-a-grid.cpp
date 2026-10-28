class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int find(int i, int j, int Xor, vector<vector<int>>& grid, vector<int>& temp, int m, int n, vector<vector<vector<int>>>& dp){
        if(i==m-1 && j==n-1){
            return Xor ^ grid[i][j];
            
        }
        int down=INT_MAX;
        int right=INT_MAX;
        if(dp[i][j][Xor]!=-1) return dp[i][j][Xor];
        if(valid(i+1, j, m, n)){
           down = find(i+1, j, Xor^grid[i][j], grid, temp, m, n, dp);
        }
        if(valid(i, j+1, m, n)){
           right = find(i, j+1, Xor^grid[i][j], grid, temp, m, n, dp);
        }
        return dp[i][j][Xor]=min(down, right);
    }
    int minCost(vector<vector<int>>& grid) {
        vector<int> temp;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return find(0, 0, 0, grid, temp, m, n, dp);
    }
};