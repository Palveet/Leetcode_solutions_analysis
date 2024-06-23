class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> maxh;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        string ans = "";
        for (const auto& ele : mp) {
            maxh.push({ele.second, ele.first});
        }
        while (maxh.size() > 0) {
            int tempFreq = maxh.top().first;
            char a = maxh.top().second;
            while (tempFreq > 0) {
                ans += a;
                tempFreq--;
            }
            maxh.pop();
        }
        return ans;
    }
};

//TC: O(N)
//SC: O(N)