class Solution {
public:
    int GCD(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi, nums[i]);
            int gcd=GCD(nums[i], maxi);
            prefixGcd.push_back(gcd);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans=0;
        int beg=0;
        int end=prefixGcd.size()-1;
        while(beg<end){
            ans+=GCD(prefixGcd[beg], prefixGcd[end]);
            beg++;
            end--;
        }
        return ans;
    }
};