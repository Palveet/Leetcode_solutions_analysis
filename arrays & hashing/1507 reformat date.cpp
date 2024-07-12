class Solution {
public:
    string reformatDate(string date) {
        string day = "";
        string month = "";
        string year = "";
        string ans = "";
        int n = date.length();
        year = date.substr(n - 4);
        month = date.substr(n - 8, 3);
        if (month == "Jan") {
            month = "01";
        }
        if (month == "Feb") {
            month = "02";
        }
        if (month == "Mar") {
            month = "03";
        }
        if (month == "Apr") {
            month = "04";
        }
        if (month == "May") {
            month = "05";
        }
        if (month == "Jun") {
            month = "06";
        }
        if (month == "Jul") {
            month = "07";
        }
        if (month == "Aug") {
            month = "08";
        }
        if (month == "Sep") {
            month = "09";
        }
        if (month == "Oct") {
            month = "10";
        }
        if (month == "Nov") {
            month = "11";
        }
        if (month == "Dec") {
            month = "12";
        }
        for (int i = 0; i < n; i++) {
            if (date[i] == 't' ||
             date[i] =='s' ||
             date[i] =='r' ||
             date[i] == 'n') {
                break;
            }
            day += date[i];
        }
        if(stoi(day)<10){
            day="0"+day;
        }
        ans += year + "-" + month +"-"+ day;
        return ans;
    }
};

//TC:O(N);
//SC:O(1);