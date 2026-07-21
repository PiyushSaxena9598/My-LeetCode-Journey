class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();

        vector<pair<int, int>> v;

        // Store {row_index, number_of_ones}
        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    cnt++;
                }
            }

            v.push_back({i, cnt});
        }

        // Sort by number of soldiers
        // If equal, sort by row index
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first < b.first;

            return a.second < b.second;
        });

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};