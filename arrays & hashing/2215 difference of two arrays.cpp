class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>n1;
        unordered_set<int>n2;
        for(int i=0;i<nums1.size();i++){
            n1.insert(nums1[i]);
        }
         for(int i=0;i<nums2.size();i++){
            n2.insert(nums2[i]);
        }
        vector<vector<int>>ans;
        ans.push_back({});
        ans.push_back({});
        for(const auto& element:n1){
            if(n2.find(element)==n2.end()){
                ans[0].push_back(element);
            }
        }
        for(const auto& element:n2){
            if(n1.find(element)==n1.end()){
                ans[1].push_back(element);
            }
        }
        return ans;
    }
};

//TC O(N)
//SC O(N)