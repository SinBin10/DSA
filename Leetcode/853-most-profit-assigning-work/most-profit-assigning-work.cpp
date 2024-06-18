class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int size = worker.size();
        int j = 0;
        int maxi = 0;
        int maxProfit = 0;
        map<int,int> mp;
        for(int i = 0;i<profit.size();i++){
            if(mp.find(difficulty[i]) != mp.end()){
                int maxu = max(mp[difficulty[i]],profit[i]);
                mp[difficulty[i]] = maxu;
            }
            else
            mp[difficulty[i]] = profit[i];
        }
        for(auto it: mp){
            maxi = max(maxi, it.second);
            mp[it.first] = maxi;
        }
        while(j<size){
            int profit = 0;
            for(auto it: mp){
                if(worker[j]>=it.first){
                    profit = it.second;
                }
                else
                break;
            }
            maxProfit+=profit;
            ++j;
        }
        return maxProfit;
    }
};