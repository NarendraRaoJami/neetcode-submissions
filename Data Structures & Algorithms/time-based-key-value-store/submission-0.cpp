class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hash;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!hash.count(key))
            return "";

        int left = 0, right = hash[key].size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (hash[key][mid].first == timestamp)
                return hash[key][mid].second;
            else if (hash[key][mid].first > timestamp)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (right == -1)
            return "";

        return hash[key][right].second;
    }
};