class Solution {
public:
    int find(vector<int>& nums){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        maxi=max(maxi, nums[i]);

        vector<int> temp(maxi+1, 0);
        for(int i=0;i<nums.size();i++)
        temp[nums[i]]++;

        int count=0;
        for(int i=0;i<temp.size();i++)
        if(temp[i]!=0) 
        count++;

        return count;
    }
    int sumCounts(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        
        vector<vector<int>> allSubarrays;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> currentSubarray;
                for (int k = i; k <= j; k++) {
                    currentSubarray.push_back(nums[k]);
                }
                allSubarrays.push_back(currentSubarray);
            }
        }
        for(int i=0;i<allSubarrays.size();i++){
            int a=find(allSubarrays[i]);
            ans+=a*a;
        }
        return ans;
    }
};