class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp = x;
        long r=0;     
        while(x){
         r=r*10+x%10; 
         x=x/10;     
        } 
        return temp==int(r); 
    }
};

//TC: O(Log(x))
//SC: O(1)