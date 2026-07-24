class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i>=prices.size())
        return 0;
        int profit=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            // buy the stock
            int buyStock=-prices[i]+solve(i+1, 0, prices, dp);
            // skip the stock
            int skip=solve(i+1, 1, prices, dp);
            profit=max(buyStock, skip);
        }else{
            // sell stock
            int sellStock=prices[i]+solve(i+2, 1, prices, dp); 
            // don't sell
            int skip=solve(i+1, 0, prices, dp);
            profit=max(sellStock, skip);
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};