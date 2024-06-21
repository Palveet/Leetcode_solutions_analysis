class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>mp;
        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }
        int counter =1;
        while(counter){
            if(mp.find(counter)!=mp.end()){
                counter++;
            }
            else{
                return counter;
            }
        }
        return counter;
    }
};

//TC: O(N)
//SC: O(N)