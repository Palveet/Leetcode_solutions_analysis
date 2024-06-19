class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1;
        unordered_set<int>s2;
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            s2.insert(nums2[i]);
        }
        vector<int>ans;
        for(const auto& element:s2){
            if(s1.find(element)!=s1.end()){
                ans.push_back(element);
            }
        }
        return ans;
    }
};

//TC: O(N)
//SC: O(N)