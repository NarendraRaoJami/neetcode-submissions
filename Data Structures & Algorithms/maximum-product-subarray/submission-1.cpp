class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int cur_min = 1,cur_max = 1;
        for(int num : nums){
            int temp = cur_max*num;
            cur_max = max(max(num*cur_min,num*cur_max),num);
            cur_min = min(min(temp,num*cur_min),num);
            result = max(result,cur_max);
        }
        return result;
    }
};
