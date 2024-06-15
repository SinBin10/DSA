class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> ans;
        for(int i = 0;i<profits.size();i++){
            ans.push_back({capital[i],profits[i]});
        }
        sort(ans.begin(),ans.end());
        for(int i = 0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
        priority_queue<int> pq;
        int i = 0;
        while(k--){
            while(i<ans.size() && ans[i].first <= w){
                pq.push(ans[i].second);
                ++i;
            }
            if(pq.empty())
            break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};