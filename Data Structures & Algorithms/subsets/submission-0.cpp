class Solution {
    vector<vector<int>> result;
    void solve(vector<int>& nums, int index, vector<int>& temp){
        if(index == nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(nums, index+1, temp);
        temp.pop_back();
        solve(nums, index+1, temp);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);
        return result;
    }
};
