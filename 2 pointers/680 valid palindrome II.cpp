class Solution {
public:
    bool validPalindrome(string s) {
        int i =0;
        int j =s.size()-1;
        int count=0;
        while(i<j){
            if(s[i]!=s[j]){
                string one = s;
                string two = s;
                one.erase(one.begin()+i);
                two.erase(two.begin()+j);
                string oneRev = one;
                string twoRev = two;
                reverse(one.begin(),one.end());
                reverse(two.begin(),two.end());
                if(one== oneRev || two==twoRev){
                    return true;
                } else {
                    return false;
                }
            } 
            i++;
            j--;
        }
        return true;
    }
};


//TC:O(N)
//SC:O(1)