class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int count=0;
            int val=nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(val%2==0 && nums[j]%2!=0)
                count++;
                if(val%2!=0 && nums[j]%2==0)
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};