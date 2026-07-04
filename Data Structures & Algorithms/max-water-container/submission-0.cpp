class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int result = 0;
        while(left < right){
            result = max(result,(right-left)*min(heights[left],heights[right]));
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return result;
    }
};
