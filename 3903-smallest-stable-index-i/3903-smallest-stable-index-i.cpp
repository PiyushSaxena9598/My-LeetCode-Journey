class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(int j=0;j<=i;j++){
                maxi=max(maxi, nums[j]);
            }
            for(int k=i;k<nums.size();k++){
                mini=min(mini, nums[k]);
            }
            if(maxi-mini<=k)
                return i;
        }
        return -1;
    }
};