class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> hash;
        for(int i = 0;i < n;i++){
            hash.push_back({position[i],(double)(target - position[i])/speed[i]});
        }
        sort(hash.rbegin(),hash.rend());
        stack<double> st;
        for(int i = 0;i < n;i++){
            double time = hash[i].second;
            if(st.empty() || time > st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};
