class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n, -1);
        int max_inv = 0;
        
        for (const auto& r : requirements) {
            req[r[0]] = r[1];
            max_inv = max(max_inv, r[1]);
        }
        
        if (req[0] > 0) {
            return 0;
        }
        req[0] = 0; 
        
        const int MOD = 1e9 + 7;
        vector<vector<int>> f(n, vector<int>(max_inv + 1, 0));
        f[0][0] = 1;
        
        for (int i = 1; i < n; ++i) {
            int l = 0, r_bound = max_inv;
            if (req[i] != -1) {
                l = r_bound = req[i];
            }
            
            for (int j = l; j <= r_bound; ++j) {
                for (int k = 0; k <= min(i, j); ++k) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
                }
            }
        }
        
        return f[n - 1][req[n - 1]];
    }
};