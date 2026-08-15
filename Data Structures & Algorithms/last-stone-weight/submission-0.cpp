class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int stone : stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size() >= 2){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if(x != y){
                maxHeap.push(abs(x-y));
            }
        }
        if(maxHeap.size() == 0){
            return 0;
        }
        return maxHeap.top();
    }
};
