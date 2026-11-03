class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        maxi=max(maxi, nums[i]);

        int sum=maxi*n;
        int res=0;
        for(int i=0;i<n;i++){
            res+=nums[i];
        }
        return sum-res;
    }
};