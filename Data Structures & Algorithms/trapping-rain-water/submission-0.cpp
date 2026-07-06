class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }

        int left = 0,right = height.size()-1;
        int leftmax = height[left],rightmax = height[right];
        int result = 0;

        while(left < right){
            if(leftmax < rightmax){
                left++;
                leftmax = max(leftmax,height[left]);
                result += leftmax - height[left];
            }
            else{
                right--;
                rightmax = max(rightmax,height[right]);
                result += rightmax - height[right];
            }
        }
        return result;
    }
};
