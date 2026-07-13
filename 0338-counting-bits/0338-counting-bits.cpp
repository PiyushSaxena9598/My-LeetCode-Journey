class Solution {
public:
    int count(int n, vector<int>& dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(n%2)+count(n/2, dp);
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        vector<int> dp(n+1, -1);
        for(int i=0;i<=n;i++)
        ans.push_back(count(i, dp));
        return ans;
    }
};