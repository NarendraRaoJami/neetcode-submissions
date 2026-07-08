class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{-1,0},{1,0}};
    bool check(vector<vector<char>>& board,string word,int row,int col,int index){
        if(index == word.size()){
            return true;
        }
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()
            || board[row][col] != word[index] || board[row][col] == '#'){
                return false;
            }

        board[row][col] = '#';
        bool res = false;
        for(int i = 0;i < 4;i++){
            int new_row = row + dirs[i].first;
            int new_col = col + dirs[i].second;

            res = res||check(board,word,new_row,new_col,index+1);
        }
        board[row][col] = word[index];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(check(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
