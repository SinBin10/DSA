class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<bool>> v(row,vector<bool>(col,true));
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j] == 0)
                v[i][j] = false;
            }
        }
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j] == 0 && v[i][j] == false){
                    for(int k = 0;k<row;k++){
                        matrix[k][j] = 0;
                    }
                    for(int k = 0;k<col;k++){
                        matrix[i][k] = 0;
                    }
                }
            }
        }
    }
};