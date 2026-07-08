class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        int n = s.size();

        vector<int> nz;            
        vector<int> nd;             

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                nz.push_back(i);
                nd.push_back(s[i] - '0');
            }
        }

        int k = nz.size();
        vector<long long> prefSum(k+1, 0), prefHash(k+1, 0), pow10(k+1, 1);

        for (int i = 1; i <= k; i++) {
            prefSum[i] = prefSum[i-1] + nd[i-1];
            prefHash[i] = (prefHash[i-1] * 10 + nd[i-1]) % MOD;
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(nz.begin(), nz.end(), l) - nz.begin();
            int R = upper_bound(nz.begin(), nz.end(), r) - nz.begin() - 1;

            if (L > R) {    
                ans.push_back(0);
                continue;
            }

            int cnt = R - L + 1;
            long long x = prefHash[R+1] -
                          (prefHash[L] * pow10[cnt] % MOD);
            if (x < 0) x += MOD;

            long long sum = prefSum[R+1] - prefSum[L];
            long long val = (x % MOD) * (sum % MOD) % MOD;

            ans.push_back((int)val);
        }

        return ans;
    }
};