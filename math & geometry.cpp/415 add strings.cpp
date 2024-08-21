class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        while(i >=0 && j>=0){
            int a = num1[i] - '0';
            int b = num2[j] - '0';
            int add = a+b+carry;
            i--;
            j--;
            if(add>=10){
                carry = add/10;
                ans=ans+ to_string(add%10);
            } else {
                ans+=to_string(add);
                carry = 0;
            }
        }
        while(i>=0){
            int a = num1[i] - '0';
            int add = a+carry;
            i--;
            if(add>=10){
                carry = add/10;
                ans=ans+ to_string(add%10);
            } else {
                ans+=to_string(add);
                carry = 0;
            }
        }
        while(j>=0){
            int a = num2[j] - '0';
            int add = a+carry;
            j--;
            if(add>=10){
                carry = add/10;
                ans=ans+ to_string(add%10);
            } else {
                ans+=to_string(add);
                carry = 0;
            }
        }
        if(carry>0){
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//TC:O(N)
//SC:O(1)