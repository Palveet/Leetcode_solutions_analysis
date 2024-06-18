class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>s;
        int atIndex = -1;
        for(int i=0;i<emails.size();i++){
            string email = "";
            for(int j = 0;j<emails[i].size();j++){
                if(emails[i][j]=='.' && atIndex<0){
                    continue;
                }
                else if(emails[i][j]=='+' && atIndex<0){
                    while(atIndex<0){
                        if(emails[i][j]=='@'){
                            atIndex = j;
                            email+=emails[i][j];
                            continue;
                        }
                        j++;
                    }
                }
                else if((emails[i][j]=='.' || emails[i][j]=='+') && atIndex>0){
                    email+=emails[i][j];
                }
                else{
                    email+=emails[i][j];
                    if(emails[i][j]=='@'){
                        atIndex = j;
                    }
                }
            }
            s[email]++;
            atIndex=-1;
        }
        return s.size();
    }
};

//TC: O(n * m)
//SC:  O(n * m)