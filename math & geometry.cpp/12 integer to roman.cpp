class Solution {
public:
    string intToRoman(int num) {
        string s="";
       while(num>=1000)
       {
           s+="M";
           num=num-1000;
       }
       if(num>=900)
       {
           s+="CM";
           num=num-900;
       }
       while(num>=500)
       {
           s+="D";
           num=num-500;
       }
       if(num>=400)
       {
           s+="CD";
           num=num-400;
       }
       while(num>=100)
       {
           s+="C";
           num=num-100;
       }
       if(num>=90)
       {
           s+="XC";
           num=num-90;
       }
       while(num>=50)
       {
           s+="L";
           num=num-50;
       }
       if(num>=40)
       {
           s+="XL";
           num=num-40;
       }
       while(num>=10)
       {
           s+="X";
           num=num-10;
       }
       if(num>=9)
       {
           s+="IX";
           num=num-9;
       }
       while(num>=5)
       {
           s+="V";
           num=num-5;
       }
       if(num>=4)
       {
           s+="IV";
           num=num-4;
       }
       while(num>=1)
       {
           s+="I";
           num=num-1;
       }
       return s; 
    }
};

//TC: O(N)
//SC: O(1)