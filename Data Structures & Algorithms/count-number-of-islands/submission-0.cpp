class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int row,int col,const vector<vector<char>>& board,vector<vector<bool>>& visited){
        visited[row][col] = true;
        for(int i = 0;i < 4;i++){
            int new_row = row + dirs[i].first;
            int new_col = col + dirs[i].second;

            if(new_row >= 0 && new_row < board.size() &&
                new_col >= 0 && new_col < board[0].size() && board[new_row][new_col] == '1'
                && !visited[new_row][new_col]){
                    dfs(new_row,new_col,board,visited);
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};
