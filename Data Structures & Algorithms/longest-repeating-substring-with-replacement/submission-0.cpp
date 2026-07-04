class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int result = 0;

        int left = 0;
        int max_f = 0;
        for(int right = 0;right < s.size();right++){
            count[s[right]]++;
            max_f = max(max_f,count[s[right]]);

            while((right-left+1) - max_f > k){
                count[s[left]]--;
                left++;
            }
            result = max(result,right-left+1);
        }
        return result;
    }
};
