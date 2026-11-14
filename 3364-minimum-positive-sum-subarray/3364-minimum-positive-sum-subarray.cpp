class Solution {
public:
    int check(vector<int>& nums, int i, int j){
        int sum = 0;
        // Fix: iterate using a temporary pointer k from i to j
        for (int k = i; k <= j; k++) {
            sum += nums[k];
        }
        return sum;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
       // vector<vector<int>> temp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if((j-i+1>=l && j-i+1<=r)){
                    int a=check(nums, i, j);
                    if(a>0)
                    ans=min(ans, a);
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};