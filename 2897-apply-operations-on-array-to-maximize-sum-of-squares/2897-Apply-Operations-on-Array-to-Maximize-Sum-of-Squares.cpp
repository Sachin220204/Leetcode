class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(31, 0);
        for (int x : nums) {
            for (int i = 0; i <= 30; ++i) {
                if ((x >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        
        long long ans = 0;
        long long MOD = 1e9 + 7;
        
        for (int step = 0; step < k; ++step) {
            long long curr = 0;
            for (int i = 30; i >= 0; --i) {
                if (bitCount[i] > 0) {
                    curr |= (1LL << i);
                    bitCount[i]--;
                }
            }
            ans = (ans + curr * curr) % MOD;
        }
        
        return ans;
    }
};