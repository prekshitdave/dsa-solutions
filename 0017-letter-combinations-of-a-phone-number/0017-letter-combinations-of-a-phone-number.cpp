
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string curr = "";

        backtrack(digits, 0, curr, ans, mp);

        return ans;
    }

    void backtrack(string& digits, int index, string& curr,
                   vector<string>& ans, vector<string>& mp) {
        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            curr.push_back(ch);

            backtrack(digits, index + 1, curr, ans, mp);

            curr.pop_back();
        }
    }
};
