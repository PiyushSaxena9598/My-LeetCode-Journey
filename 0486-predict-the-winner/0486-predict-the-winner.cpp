class Solution {
public:
    int fun(int i, int j, int turn, vector<int>& nums){
        if(i==j) return nums[i];

        if(turn%2==0)
        return max(nums[i]+fun(i+1, j, 1-turn, nums), nums[j]+fun(i,j-1, 1-turn, nums));
        else
        return min(fun(i+1, j, 1-turn, nums)-nums[i], fun(i, j-1, 1-turn, nums)-nums[j]);
    }
    bool predictTheWinner(vector<int>& nums) {
        return fun(0, nums.size()-1, 0, nums)>=0;
    }
};