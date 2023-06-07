class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {


        // Approach 1 T=O(n^2) S=O(n^2)

        vector<vector<int>> mat=matrix;

        for(int i=0;i<matrix.size();i++){
            for(int j=matrix.size()-1;j>=0;j--){
                matrix[i][matrix.size()-1-j]=mat[j][i];
            }
        }



        // Approach 2 T=O(n^2)+O(n^2) S=O(1)
        
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                swap(matrix[j][i],matrix[i][j]);     
            }
            reverse(matrix[i].begin(),matrix[i].end());
        }


    }
};