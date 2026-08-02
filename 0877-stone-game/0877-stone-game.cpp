class Solution {
public:
    int fun(int i, int j, int turn, vector<int>& piles, vector<vector<int>>& dp){
        if(i==j) return piles[i];
        if(dp[i][j]!=-1) return dp[i][j];
        if(turn%2==0){
            return dp[i][j]=max(piles[i]+fun(i+1, j, 1-turn, piles, dp), piles[j]+fun(i, j-1, 1-turn, piles, dp));
        }
        else{
            return dp[i][j]=min(fun(i+1, j, 1-turn, piles, dp)-piles[i], fun(i, j-1, 1-turn, piles, dp)-piles[j]);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return fun(0, piles.size()-1, 0, piles, dp)>=0;
    }
};