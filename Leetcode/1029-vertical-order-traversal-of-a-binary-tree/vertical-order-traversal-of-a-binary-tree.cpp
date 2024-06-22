/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int,int>>> mp;
        int col = 0;
        int row = 0;
        int c = 1;
        stack<pair<int,TreeNode*>> st1;
        stack<pair<int,TreeNode*>> st2;
        mp[col].push_back({row,root->val});
        st1.push({col,root});
        while (!st1.empty()) {
            ++row;
            while (!st1.empty()) {
                pair<int,TreeNode*> temp = st1.top();
                if(temp.second->left != NULL){
                    mp[temp.first - c].push_back({row,temp.second->left->val});
                    st2.push({temp.first - c,temp.second->left});
                }
                if(temp.second->right != NULL){
                    mp[temp.first + c].push_back({row,temp.second->right->val});
                    st2.push({temp.first + c,temp.second->right});
                }
                st1.pop();
            }
            while (!st2.empty()) {
                pair<int,TreeNode*> node = st2.top();
                if(node.second!=NULL)
                st1.push(st2.top());
                st2.pop();
            }
        }
        // for(auto it : mp){
        //     vector<pair<int,int>> v = it.second;
        //     cout<<v.size()<<" ";
        //     cout<<it.first<<" "<<"{";
        //     for(int i = 0;i<v.size();i++){
        //         cout<<"{"<<v[i].first<<",";
        //         cout<<v[i].second<<"}";
        //     }
        //     cout<<"}"<<endl;
        // }
        for (auto it : mp) {
            vector<pair<int,int>> v = it.second;
            vector<int>finaltemp;
            if(v.size() == 1){
                finaltemp.push_back(v[0].second);
            }
            else{
                int i = 1;
                while(i<v.size()){
                    vector<int> temp;
                    temp.push_back(v[i-1].second);
                    while(i<v.size() && v[i].first == v[i-1].first){
                        temp.push_back(v[i].second);
                        ++i;
                    }
                    sort(temp.begin(),temp.end());
                    for(int j = 0;j<temp.size();j++)
                    finaltemp.push_back(temp[j]);
                    ++i;
                }
                if(v[v.size()-1].first != v[v.size()-2].first)
                finaltemp.push_back(v[v.size()-1].second);
            }
            ans.push_back(finaltemp);
        }
        return ans;
    }
};