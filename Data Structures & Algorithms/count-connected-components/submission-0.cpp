class Solution {
public:
    void dfs(int node,vector<bool>& visited,const vector<vector<int>>& adj){
        if(visited[node]){
            return;
        }
        visited[node] = true;
        for(int n : adj[node]){
            if(!visited[n]){
                dfs(n,visited,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        vector<bool> visited(n,false);
        for(int i = 0;i <n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};
