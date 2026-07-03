class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int n : nums){
            hash[n]++;
        }
        vector<int> result;
        vector<pair<int,int>> arr;
        for(const auto& p : hash){
            arr.push_back({p.second,p.first});
        }
        sort(arr.rbegin(),arr.rend());
        for(int i = 0;i < k;i++){
            result.push_back(arr[i].second);
        }
        return result;
        
    }
};
