class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i <= n + 1; i++) {
            int mul = i * k;
            if (s.find(mul) == s.end()) {
                return mul;
            }
        }
        return -1; 
    }
};