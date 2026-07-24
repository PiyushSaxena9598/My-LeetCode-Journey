class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        long long total = 0;

        // Calculate total sum
        for (int x : nums) {
            total += x;
        }

        long long leftSum = 0;
        long long minDiff = LLONG_MAX;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            // Add current element to left part
            leftSum += nums[i];

            // Calculate left average
            long long leftAvg = leftSum / (i + 1);

            // Calculate right average
            long long rightAvg = 0;

            if (i != n - 1) {
                long long rightSum = total - leftSum;
                rightAvg = rightSum / (n - i - 1);
            }

            // Calculate difference
            long long diff = abs(leftAvg - rightAvg);

            // Update answer
            if (diff < minDiff) {
                minDiff = diff;
                ans = i;
            }
        }

        return ans;
    }
};