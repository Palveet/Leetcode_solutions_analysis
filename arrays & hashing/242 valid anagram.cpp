class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        for(int i=0;i<s.size();i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        for(int i=0;i<smap.size();i++){
            if(smap[i]!=tmap[i])return false;
        }
        return true;
    }
};
//O(N)


// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         unordered_map<char, int> count;
        
//         for (auto x : s) {
//             count[x]++;
//         }
        
//         for (auto x : t) {
//             count[x]--;
//         }
        
//         for (auto x : count) {
//             if (x.second != 0) {
//                 return false;
//             }
//         }
        
//         return true;
//     }
// };

// count solution : 7ms, 9.67mb
// unordered map solution : 8ms, 10.16mb