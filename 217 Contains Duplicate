class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])!=s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};


//map solution

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int,int>mp;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
//         for(const auto& pair: mp){
//             if(pair.second>1)return true;
//         }
//         return false;
//     }
// };


// Time and space complexity for different data structures.
// map : 75.84mb, 134ms
// unordered_map : 75.21mb, 100ms
// unordered_set : 73.2mb, 88ms -> optimized.
// set : 73.12mb, 109ms

//for map and set solutions the unordered part.