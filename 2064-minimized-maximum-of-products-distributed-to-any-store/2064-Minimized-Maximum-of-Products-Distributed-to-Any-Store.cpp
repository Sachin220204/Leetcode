class Solution {
public:

    bool isPossible(vector<int>& quantities, int n, int maxProducts) {
        int stores = 0;

        for (int q : quantities) {
            stores += (q + maxProducts - 1) / maxProducts;

            if (stores > n)
                return false;
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());

        int answer = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(quantities, n, mid)) {
                answer = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return answer;
    }
};