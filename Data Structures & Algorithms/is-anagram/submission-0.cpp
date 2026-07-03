class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash;
        for(char c : s){
            hash[c]++;
        }
        for(char c : t){
            hash[c]--;
        }
        for(auto [ch,val] : hash){
            if(hash[ch] != 0){
                return false;
            }
        }
        return true;
    }
};
