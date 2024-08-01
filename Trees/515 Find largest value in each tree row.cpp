
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int length = q.size();
            int maximum = INT_MIN;
            for(int i =0 ;i<length;i++){
                TreeNode* front = q.front();
                q.pop();
                maximum = max(front->val,maximum);
                
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
            }
            ans.push_back(maximum);
        }

        return ans;
    }
};

//TC: O(N)
//SC: O(N)