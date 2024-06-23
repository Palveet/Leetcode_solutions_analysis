class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        cout<<nums.size()<<endl;
        for(const auto& element:mp){
            cout<<element.first<<" "<<element.second<<endl;
        }
        int answer = 0;
        for (auto& element : mp) {
            int count = element.second;
            
            if (count == 1) {
                return -1;
            }
            
            if (count % 3 == 0) {
                answer += count / 3;
            } else if (count % 3 == 1) {
                if (count < 4) {
                    return -1;
                }
                answer += (count / 3) - 1 + 2; 
            } else { 
                answer += count / 3 + 1;
            }
        }
        return answer;
    }
};


//TC: O(N)
//SC: O(N)