class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> result;

        vector<string> phone = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string current;

        solve(digits, 0, current, result, phone);

        return result;
    }

private:
    void solve(string& digits, int index, string& current,
               vector<string>& result, vector<string>& phone) {


        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

 
        string letters = phone[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);

            solve(digits, index + 1, current, result, phone);

            current.pop_back();
        }
    }
};