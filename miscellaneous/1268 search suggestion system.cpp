class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        sort(products.begin(),products.end());
        string s="";
        for(int i=0;i<searchWord.size();i++){
            s+=searchWord[i];
            vector<string>temp;
            for(int j=0;j<products.size();j++){
                string check = products[j].substr(0,i+1);
                if(check==s && temp.size()<3){
                    temp.push_back(products[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//TC:O(N*M*LOG(M))
//SC:O(N*M)