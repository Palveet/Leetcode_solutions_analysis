class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 1;
        int y = 1;
        int visited = x*10000+y;
        unordered_set<int> s;
        s.insert(visited);
        for(int i=0;i<path.size();i++){
            if(path[i]=='N'){
                y++;
            }
            if(path[i]=='E'){
                x++;
            }
            if(path[i]=='S'){
                y--;
            }
            if(path[i]=='W'){
                x--;
            }
            visited = x*10000+y;
            if(s.count(visited)==1)return true;
            s.insert(visited);
        }       
        return false;
    }
};

//TC: O(N)
//SC: O(N)