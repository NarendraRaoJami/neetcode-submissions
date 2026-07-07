class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());

        int result = right;

        while(left <= right){
            int k = left + (right - left)/2;

            long long totalTime = 0;
            for(int p : piles){
                totalTime += ceil(static_cast<double>(p)/k);
            }
            if(totalTime <= h){
                result = k;
                right = k-1;
            }
            else{
                left = k + 1;
            }
        }
        return result;
    }
};
