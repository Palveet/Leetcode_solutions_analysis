class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // whitespacing check
        while(s[i] == ' ') i++;
        // sign check
        bool sign = s[i] == '-' || s[i] == '+';
        bool neg = s[i] == '-';
        // if sign was -ve
        if(sign) i++;
        int first_dig = i;
        int last_dig = i;
        long long int num = 0;

        for(int j = i; j < n; j++)
        {
            if(s[j] >= '0' && s[j] <= '9')
            {
                last_dig = j;
            }
            else
            {
                break;
            }
        }
        for(int j = last_dig; j >= first_dig && s[j] >= '0' && s[j] <= '9'; j--)
        {
            if(!neg && num + (s[j] - '0') * pow(10, last_dig - j) > INT_MAX)
            {
                num = INT_MAX;
                break;
            }
            else if(neg && ((num + (s[j] - '0') * pow(10, last_dig - j) * -1) < INT_MIN))
            {
                num = INT_MIN;
                break;
            }
            num += (s[j] - '0') * pow(10, last_dig - j);
        }

        if(neg) 
        {
            num *= -1;
            num = max(num, (long long int)(INT_MIN));
        }
        else
        {
            num = min(num, (long long int)(INT_MAX));
        }
        
        return num;
    }
};