class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = nums.size();
        if(freq == 0)return 0;
        if(freq == 1)return nums[0];
        int intended = freq/2;
        map<int, int> frequencyMap;
        for(int i = 0;i<freq;i++){
            if(!frequencyMap[nums[i]]){
            frequencyMap[nums[i]]=1;
            
            if(!frequencyMap[nums[i]]>intended){
                return nums[i];
            }
            }
            else {
            frequencyMap[nums[i]]+=1; 
            if(frequencyMap[nums[i]]>intended){
                return nums[i];
            }
            }
        }
        return 0;
    }
};

//TC: O(nlogn)
//sc: o(n)