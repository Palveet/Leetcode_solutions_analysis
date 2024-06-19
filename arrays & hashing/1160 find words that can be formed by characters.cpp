class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> ch;
        int ans = 0;
        for (int i = 0; i < chars.size(); i++) {
            ch[chars[i]]++;
        }
        for (int i = 0; i < words.size(); i++) {
            unordered_map<char, int> word;
            for (int j = 0; j < words[i].size(); j++) {
                word[words[i][j]]++;
            }
            int count = 0;
            for (const auto& w : word) {
                if(w.second<=ch[w.first]){
                    count+=w.second;
                }
            }
            if(count == words[i].size()){
                ans+=count;
            }
        }
        return ans;
    }
};

//TC: O(N*M)
//SC: O(N+M)