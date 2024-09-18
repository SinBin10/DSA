class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<bool>> boolean(matrix.size(),vector<bool> (matrix[0].size(),true));
        for(int i = 0;i<boolean.size();i++){
            for(int j = 0;j<boolean[0].size();j++){
                if(matrix[i][j] == 0)
                boolean[i][j] = 0;
            }
        }
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0 && boolean[i][j] == 0){
                    int row = 0;
                    int col = 0;
                    while(row<matrix.size()){
                        matrix[row][j] = 0;
                        ++row;
                    }
                    while(col<matrix[0].size()){
                        matrix[i][col] = 0;
                        ++col;
                    }
                }
            }
        }
        // for(int i = 0;i<boolean.size();i++){
        //     for(int j = 0;j<boolean[0].size();j++){
        //         cout<<matrix[i][j]<<",";
        //     }
        //     cout<<endl;
        // }
    }
};