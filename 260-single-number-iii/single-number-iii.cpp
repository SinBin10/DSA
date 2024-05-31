class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n1 = 0,n2 = 0;
        int check = true;
        for(int i = 0;i<nums.size();i++)
        ++mp[nums[i]];
        for(auto it:mp){
            if(it.second == 1){
                if(check){
                    n1 = it.first;
                    check = false;
                }
                else
                return {n1,it.first};
            }
        }
        return {};
    }
};