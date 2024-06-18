class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>sumLeft;
        vector<int>sumRight;
        sumLeft.push_back(0);
        int sumL = 0;
        for(int i = 1;i<nums.size();i++){
            sumL+=nums[i-1];
            sumLeft.push_back(sumL);
        }
        sumRight.push_back(0);
        int sumR = 0;
        for(int i = nums.size()-2;i>=0;i--){
            sumR+=nums[i+1];
            sumRight.push_back(sumR);
        }
        reverse(sumRight.begin(),sumRight.end());
        for(int i =0;i<sumLeft.size();i++){
            cout<<sumLeft[i]<<' '<<sumRight[i];
            if(sumLeft[i]==sumRight[i]){
                return i;
            }
        }
        return -1;
    }
};

//TC: O(N)
//SC: O(N)