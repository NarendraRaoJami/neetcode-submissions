class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1] < b[1];
            
        });
        vector<pair<int,int>> result;
        result.push_back({intervals[0][0],intervals[0][1]});
        for(int i = 1;i < intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int prev_start = result.back().first;
            int prev_end = result.back().second;

            if(start >= prev_end){
                result.push_back({start,end});
            }
        }
        return intervals.size() - result.size();
    }
};
