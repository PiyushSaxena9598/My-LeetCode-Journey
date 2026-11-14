class Solution {
public:
    bool check(const string& s, int beg, int end, vector<vector<int>>& dp){
        if(beg>=end) return true;

        if(dp[beg][end]!=-1) return dp[beg][end];

        if(s[beg]==s[end]){
           return dp[beg][end]=check(s, beg+1, end-1, dp);
        }
        else
        return dp[beg][end]=false;
    }
    string longestPalindrome(string s) {
        string ans="";
        int maxi=-1;
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s, i, j, dp)){
                    if(j-i+1>maxi){
                        maxi=j-i+1;
                        ans=s.substr(i, j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};