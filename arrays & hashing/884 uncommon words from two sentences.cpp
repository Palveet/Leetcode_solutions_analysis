class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>res;
        unordered_map<string, int> map;
        string w = "";
        for (auto c : s1) {
            if (c == ' ') {
                map[w]++;
                w = "";
            } else
                w += c; 
        }
        map[w]++; 
        w = "";
        for (auto c : s2) {
            if (c == ' ') {
                map[w]++;
                w = "";
            } else
                w += c;
        }
        map[w]++;
        for (auto i : map) {
            if (i.second == 1) {
                res.push_back(i.first);
            }
        }
        return res;
    }
};

//TC:O(N)
//SC:O(N)