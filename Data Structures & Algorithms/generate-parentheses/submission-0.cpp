class Solution {
    vector<string> result;

    void solve(int n, int open, int close, string& temp) {
        if (temp.size() == 2 * n) {
            result.push_back(temp);
            return;
        }
        if (open < n) {
            temp.push_back('(');
            solve(n, open + 1, close, temp);
            temp.pop_back();
        }
        if (close < open) {
            temp.push_back(')');
            solve(n, open, close + 1, temp);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string temp;
        solve(n, 0, 0, temp);
        return result;
    }
};