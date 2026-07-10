class Solution {
public:
    string longestPalindrome(string s) {
        int longest_length = 0,result_index = 0;
        for(int i = 0;i < s.size();i++){
            int left = i,right = i;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                if(right-left+1 > longest_length){
                    result_index = left;
                    longest_length = right - left + 1;
                }
                left--;
                right++;
            }
            left = i;
            right = i+1;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                if(right-left+1 > longest_length){
                    result_index = left;
                    longest_length = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return s.substr(result_index,longest_length);
    }
};
