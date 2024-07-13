class Solution {
public:
    string convert(string s, int numRows) {
        vector<char>c;
        vector<int>ind;
        int j = 0;
        while (j < s.size()) {
            for (int i = 0; i < numRows; i++) {
                if(j<s.size()){
                    c.push_back(s[j]);
                    ind.push_back(i);
                j++;
                }
            }
            for (int i = numRows-2; i >=1; i--) {
                if(j<s.size()){
                    c.push_back(s[j]);
                    ind.push_back(i);
                j++;
                }
            }
        }
        string ans = "";
        int k = 0;
        while(k<numRows){
            for(int i=0;i<c.size();i++){
                if(k==ind[i]){
                    ans+=c[i];
                }
            }
            k++;
        }
        return ans;
    }
};


//TC: O(N) coz numRows is constant
//SCl O(N)