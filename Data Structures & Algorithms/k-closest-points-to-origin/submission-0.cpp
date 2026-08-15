class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(int i = 0;i < points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            minHeap.push({x*x + y*y,i});
        }
        vector<vector<int>> result;
        for(int i = 0;i < k;i++){
            int index = minHeap.top().second;
            result.push_back({points[index][0], points[index][1]});
            minHeap.pop();
        }
        return result;
    }
};
