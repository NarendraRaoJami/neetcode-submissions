class Solution {
    vector<vector<string>> result;

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
    }

    void solve(string& s, int index, vector<string>& sub) {
        // We have partitioned the entire string
        if (index == s.length()) {
            result.push_back(sub);
            return;
        }

        // Try every possible ending position
        for (int i = index; i < s.length(); i++) {

            // s[index...i] must be a palindrome
            if (isPalindrome(s, index, i)) {

                // Choose
                sub.push_back(s.substr(index, i - index + 1));

                // Recurse on remaining string
                solve(s, i + 1, sub);

                // Undo
                sub.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> sub;
        solve(s, 0, sub);
        return result;
    }
};