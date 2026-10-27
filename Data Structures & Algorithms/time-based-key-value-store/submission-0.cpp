class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }

        const auto& entries = store[key];

        int low = 0;
        int high = entries.size() - 1;
        string res = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (entries[mid].first <= timestamp) {
                res = entries[mid].second;
                low = mid + 1;         
            } else {
                high = mid - 1;           
            }
        }

        return res;
    }
};