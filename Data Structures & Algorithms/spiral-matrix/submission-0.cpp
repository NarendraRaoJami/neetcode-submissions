class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int left = 0, right = matrix[0].size();
        int top = 0,bottom = matrix.size();

        while(left < right && top < bottom){
            for(int i = left;i < right;i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top;i < bottom;i++){
                result.push_back(matrix[i][right-1]);
            }
            right--;
            if(!(left < right && top < bottom)){
                break;
            }
            for(int i = right-1;i >= left;i--){
                result.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            for(int i = bottom-1;i >= top;i--){
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};
