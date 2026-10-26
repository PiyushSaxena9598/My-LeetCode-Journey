class Solution {
public:
    void find(vector<int>& nums, int target, int sum, int n, int& ans, int idx){
        if(idx == n){
            if(sum == target) ans++;
            return;
        }
        find(nums, target, -nums[idx]+sum, n, ans, idx+1);
        find(nums, target, nums[idx]+sum, n, ans, idx+1); 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        find(nums, target, 0, n, ans, 0);
        return ans;
    }
};