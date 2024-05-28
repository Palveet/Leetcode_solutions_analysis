// solution 1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> sortMap;
        for (int i = 0; i < strs.size(); i++) { //O(N)
            string temp = strs[i];
            sort(temp.begin(), temp.end()); //O(LlogL)
            sortMap[temp].push_back(strs[i]);
        } //overall O(N*LlogL)
        for (const auto& pair : sortMap) {
            ans.push_back(pair.second); //O(NLogN)
        } 
        return ans;
    }
};

//final complexity : O(N*L log L)

//solution 2
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(int i=0;i<strs.size();i++){ //O(N)
            string key = getKey(strs[i]);
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto i=mp.begin();i!=mp.end();i++){
            result.push_back(i->second);
        }
        return result;
    }
private:
string getKey(string s){
    vector<int>count(26);
    for(int i=0;i<s.size();i++){
        count[s[i]-'a']++; //O(L) L->length of string
    }
    string key = "";
    for(int i=0;i<count.size();i++){
        key.append(to_string(count[i])+'#'); //O(26) -> O(1)
    }
    return key;
}
};

//Final complexity : O(N*L) Space: O(N*L)