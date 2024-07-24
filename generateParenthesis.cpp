class Solution {
public:
    void helper(string curr, int open, int close, int n, vector<string>& res) {
        if (open == n && close == n) {
            res.push_back(curr);
            return;
        }

        // Open parenthesis
        if (open < n) {
            helper(curr + '(', open + 1, close, n, res);
        }

        // Close parenthesis
        if (open > close) {
            helper(curr + ')', open, close + 1, n, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("", 0, 0, n, res);
        return res;
    }
};
