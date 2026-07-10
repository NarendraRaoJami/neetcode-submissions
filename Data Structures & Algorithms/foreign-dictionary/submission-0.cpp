class Solution {
public:
    unordered_map<char,bool> visited;
    unordered_map<char,unordered_set<char>> adj;
    string result;
    string foreignDictionary(vector<string>& words) {
        for(const auto& word : words){
            for(char ch : word){
                adj[ch];
            }
        }
        for(size_t i = 0;i < words.size()-1;i++){
            const string& w1 = words[i];
            const string& w2 = words[i+1];
            size_t minlen = min(w1.length(),w2.length());
            if(w1.length() > w2.length() && w1.substr(0,minlen) == w2.substr(0,minlen)){
                return "";
            }
            for(size_t j = 0;j < minlen;j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        for(const auto& pair : adj){
            if(dfs(pair.first)){
                return "";
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }

    bool dfs(char ch){
        if(visited.find(ch) != visited.end()){
            return visited[ch];
        }
        visited[ch] = true;
        for(char next : adj[ch]){
            if(dfs(next)){
                return true;
            }
        }
        visited[ch] = false;
        result.push_back(ch);
        return false;
    }
};
