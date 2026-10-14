class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty() || s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        int minLen = INT_MAX;
        int startIdx = 0;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }

                char leftChar = s[l];
                window[leftChar]--;
                if (countT.count(leftChar) && window[leftChar] < countT[leftChar]) {
                    have--;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
