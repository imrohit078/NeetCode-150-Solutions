class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded ="";
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;


    }

    vector<string> decode(string s) {

vector<string> result;
        int i = 0;
        int n = s.length();

        while (i < n) {
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);
            result.push_back(word);
            i = j + 1 + len;
    }
    return result;
    }
};
