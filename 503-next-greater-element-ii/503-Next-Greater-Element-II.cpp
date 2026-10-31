class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; --i) {
            int currIdx = i % n;

            while (!st.empty() && nums[st.top()] <= nums[currIdx]) {
                st.pop();
            }

            if (i < n) {
                if (!st.empty()) {
                    result[currIdx] = nums[st.top()];
                }
            }

            st.push(currIdx);
        }

        return result;
    }
};