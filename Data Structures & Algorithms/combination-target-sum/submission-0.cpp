class Solution {
public:
    vector<vector<int>> result;
    void backtrack(const vector<int>& nums,int i,int target,vector<int> temp){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        if(target < 0 || i >= nums.size()){
            return;
        }
        temp.push_back(nums[i]);
        backtrack(nums,i,target-nums[i],temp);
        temp.pop_back();
        backtrack(nums,i+1,target,temp);
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        backtrack(nums,0,target,temp);
        return result;
    }
};
