class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> present(2048, false);
        vector<int> v;

        for (int x : nums) {
            if (!present[x]) {
                present[x] = true;
                v.push_back(x);
            }
        }

        vector<bool> twoXor(2048, false);

        // All possible XOR of two elements
        for (int x : v) {
            for (int y : v) {
                twoXor[x ^ y] = true;
            }
        }

        vector<bool> ans(2048, false);

        // XOR with the third element
        for (int x = 0; x < 2048; x++) {
            if (twoXor[x]) {
                for (int y : v) {
                    ans[x ^ y] = true;
                }
            }
        }

        int count = 0;

        for (int x = 0; x < 2048; x++) {
            if (ans[x])
                count++;
        }

        return count;
    }
};