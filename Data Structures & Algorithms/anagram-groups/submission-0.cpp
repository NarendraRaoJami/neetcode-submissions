class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        for(string s : strs){
            string temp = s;
            sort(s.begin(),s.end());
            hash[s].push_back(temp);
        }
        vector<vector<string>> result;
        for(auto [str,arr] : hash){
            vector<string> temp;
            for(string s : arr){
                temp.push_back(s);
            }
            result.push_back(temp);
        }
        return result;
    }
};
