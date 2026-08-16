class Solution {
    vector<vector<int>> result;

    void solve(vector<int>& a, int index, int target, vector<int>& temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (target < 0 || index == a.size()) {
            return;
        }

        for (int i = index; i < a.size(); i++) {
            if (i > index && a[i] == a[i - 1])
                continue;
            if (a[i] > target)
                break;
            temp.push_back(a[i]);
            solve(a, i + 1, target - a[i], temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        solve(candidates, 0, target, temp);

        return result;
    }
};