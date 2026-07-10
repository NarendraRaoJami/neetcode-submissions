class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto& pre : prerequisites){
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }
        queue<int> q;
        for(int i = 0;i < numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int finish = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            finish++;
            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return finish == numCourses;
    }
};
