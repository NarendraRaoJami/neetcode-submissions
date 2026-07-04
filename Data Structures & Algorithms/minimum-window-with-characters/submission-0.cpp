class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()){
            return "";
        }
        unordered_map<char,int> countT,window;
        for(char ch : t){
            countT[ch]++;
        }

        int have = 0;
        int need = countT.size();
        pair<int,int> result = {-1,-1};
        int result_length = INT_MAX;
        int left = 0;
        for(int right = 0;right < s.length();right++){
            char ch = s[right];
            window[ch]++;
            if(countT.count(ch) && window[ch] == countT[ch]){
                have++;
            }
            while(have == need){
                if((right-left+1) < result_length){
                    result_length = right-left+1;
                    result = {left,right};
                }
                window[s[left]]--;
                if(countT.count(s[left]) && window[s[left]] < countT[s[left]]){
                    have--;
                }
                left++;
            }
        }
        return result_length == INT_MAX ? "" : s.substr(result.first,result_length);
    }
};
