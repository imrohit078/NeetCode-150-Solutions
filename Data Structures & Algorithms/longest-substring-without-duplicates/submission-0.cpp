class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(256, -1);
        int max_len = 0;
        int left = 0;
        for(int right = 0; right < s.length(); ++right){
            unsigned char c = s[right];
            if (last_seen[c] >= left) {
                left = last_seen[c] + 1;
            }
            last_seen[c] = right;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
