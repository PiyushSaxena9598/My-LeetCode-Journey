class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        int maxi=INT_MIN;
        for(int i=0;i<matches.size();i++){
            for(int j=0;j<matches[i].size();j++){
                maxi=max(maxi, matches[i][j]);
            }
        }
        vector<int> temp(maxi+1, 0);
        vector<int> present(maxi+1, 0);
        for(int i=0;i<matches.size();i++){
            temp[matches[i][1]]++;
            present[matches[i][0]]=1;
            present[matches[i][1]]=1;
        }
        vector<int> a;
        vector<int> b;
        for(int i=1;i<temp.size();i++){
            if(present[i]==1 && temp[i]==0) a.push_back(i);
            if(present[i]==1 && temp[i]==1) b.push_back(i);
        }
       // vector<vector<int>> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};