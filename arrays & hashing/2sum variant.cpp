int stockPairs(vector<int> stocksProfit, long target) {
unordered_map<int, int>freq;
int ans=0;
for(int i=0;i<stocksProfit.size();i++){
    freq[stocksProfit[i]]++;
}
for(const auto & ele:freq){
    if(ele.second>0 && freq.find(target-ele.first)!=freq.end() && freq[target-ele.first]>0){
        if(ele.first!=target-ele.first){
        freq[ele.first]=0;
        freq[target-ele.first]=0;   
        ans++; 
        } else if(ele.first==target-ele.first && ele.second>1){
               freq[ele.first]=0;
                freq[target-ele.first]=0;   
                ans++; 
        }
        }
}
return ans;
}

//TC:O(N)
//SC:O(N)