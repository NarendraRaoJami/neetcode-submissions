class Solution {
public:
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows,vector<bool>(cols,false));
        vector<vector<bool>> atlantic(rows,vector<bool>(cols,false));

        for(int c = 0;c < cols;c++){
            dfs(0,c,pacific,heights);
            dfs(rows-1,c,atlantic,heights);
        }
        for(int r = 0;r < rows;r++){
            dfs(r,0,pacific,heights);
            dfs(r,cols-1,atlantic,heights);
        }

        vector<vector<int>> result;
        for(int r = 0;r < rows;r++){
            for(int c = 0;c < cols;c++){
                if(pacific[r][c] && atlantic[r][c]){
                    result.push_back({r,c});
                }
            }
        }

        return result;
    }

    void dfs(int row,int col,vector<vector<bool>>& ocean,vector<vector<int>>& heights){
        ocean[row][col] = true;
        for(auto [dr,dc] : directions){
            int new_row = row + dr;
            int new_col = col + dc;
            if(new_row >= 0 && new_row < heights.size() &&
                new_col >= 0 && new_col < heights[0].size() && !ocean[new_row][new_col] &&
                    heights[new_row][new_col] >= heights[row][col]){
                        dfs(new_row,new_col,ocean,heights);
                    }
        }
    }
};
