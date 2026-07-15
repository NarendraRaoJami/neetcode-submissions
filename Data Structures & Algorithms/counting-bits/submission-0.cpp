class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0;i <= n;i++){
            int count = 0;
            int temp = i;
            while(i){
                count += i&1;
                i = (i >> 1);
            }
            i = temp;
            result.push_back(count);
        }
        return result;
    }
};
