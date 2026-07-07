class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(matrix[mid][0] == target){
                return true;
            }
            else if(matrix[mid][0] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        int row = right;
        if(row < 0){
            return false;
        }
        left = 0,right = matrix[0].size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return false;
    }
};
