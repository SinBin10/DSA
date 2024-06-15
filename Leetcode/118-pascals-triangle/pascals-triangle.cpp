class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1)
        return {{1}};
        vector<vector<int>> ans = generate(numRows - 1);
        vector<int> v;
        v.push_back(1);
        for(int i = 1;i<numRows - 1;i++){
            v.push_back(ans.back()[i] + ans.back()[i-1]);
        }
        v.push_back(1);
        ans.push_back(v);
        return ans;
    }
};