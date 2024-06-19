class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp = {
            {'b', 0},
            {'a', 0},
            {'l', 0},
            {'o', 0},
            {'n', 0}
        };
        for(char ch : text)
        {
            if(mp.find(ch) != mp.end())
            {
                mp[ch]++;
            }
        }
        int maxi = INT_MAX;
        maxi = min(maxi, mp['b']);
        maxi = min(maxi, mp['a']);
        maxi = min(maxi, mp['l'] / 2);
        maxi = min(maxi, mp['o'] / 2);
        maxi = min(maxi, mp['n']);
        
        return maxi;
    }
};

//TC: O(N)
//SC: O(1)