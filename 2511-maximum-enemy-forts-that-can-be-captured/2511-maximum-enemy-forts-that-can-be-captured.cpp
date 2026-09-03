class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        int prev = -1;

        for (int i = 0; i < forts.size(); i++) {

            if (forts[i] == 0)
                continue;

            if (prev != -1 && forts[prev] != forts[i]) {
                ans = max(ans, i - prev - 1);
            }

            prev = i;
        }

        return ans;
    }
};