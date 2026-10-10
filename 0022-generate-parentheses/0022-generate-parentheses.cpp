
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";

        backtrack(n, 0, 0, curr, ans);

        return ans;
    }

    void backtrack(int n, int open, int close,
                   string& curr, vector<string>& ans) {
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add opening bracket if available
        if (open < n) {
            curr.push_back('(');
            backtrack(n, open + 1, close, curr, ans);
            curr.pop_back();
        }

        // Add closing bracket only if it can be matched
        if (close < open) {
            curr.push_back(')');
            backtrack(n, open, close + 1, curr, ans);
            curr.pop_back();
        }
    }
};
