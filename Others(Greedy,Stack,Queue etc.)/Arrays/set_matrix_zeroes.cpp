class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        

        // Approach 1 --> T=O(m*n), S=O(m*n)

         stack<pair<int,int>> s;

         for(int i=0;i<matrix.size();i++){
             for(int j=0;j<matrix[0].size();j++){
                
                if(matrix[i][j]==0){
                    s.push({i,j});
                }

             }
         }


         while(!s.empty()){
            
            int row=s.top().first;
            int col=s.top().second;
            s.pop();

            for(int j=0;j<matrix[0].size();j++){
                if(matrix[row][j]!=0){
                    matrix[row][j]=0;
                }
            }

            for(int i=0;i<matrix.size();i++){
                if(matrix[i][col]!=0){
                    matrix[i][col]=0;
                }
            }

         }  


         // Approach 2 --> T=O(m*n), S=O(1)


         int rows=matrix.size(),cols=matrix[0].size(),c0=1,r0=1;

        for(int i=0;i<rows;i++){
            if(matrix[i][0]==0){
                r0=0;
            }
        }

        for(int j=0;j<cols;j++){
            if(matrix[0][j]==0){
                c0=0;
            }
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][0]==0 or matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        for(int i=0;i<rows;i++){
            if(r0==0) matrix[i][0]=0;
        }
        
        for(int j=0;j<cols;j++){
            if(c0==0) matrix[0][j]=0;
        }
        

    }
};