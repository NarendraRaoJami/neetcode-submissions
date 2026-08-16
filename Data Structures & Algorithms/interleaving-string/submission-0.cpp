class Solution {
    vector<vector<int>> dp;
    bool dfs(int i,int j,int k, string& s1, string& s2, string& s3){
        if(k == s3.length()){
            return (i == s1.length() && j == s2.length());
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool res = false;
        if(i < s1.length() && s1[i] == s3[k]){
            res = dfs(i+1, j, k+1, s1, s2, s3);
        }
        if(!res && j < s2.length() && s2[j] == s3[k]){
            res = dfs(i, j+1, k+1, s1, s2, s3);
        }
        dp[i][j] = res;
        return res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if(n+m != s3.length()){
            return false;
        }
        dp.assign(n+1, vector<int>(m+1, -1));
        return dfs(0, 0, 0, s1, s2, s3);
    }
};
