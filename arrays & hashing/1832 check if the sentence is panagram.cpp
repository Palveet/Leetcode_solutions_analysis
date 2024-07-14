class Solution {
public:
    bool checkIfPangram(string sentence) {
        int freq[26] ={0};
        for(auto s: sentence)
        {
            freq[s - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] == 0) return false;
        }
        return true;
    }
};

//TC: O(N)
//SC: O(N)