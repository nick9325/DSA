class Solution {
public:

    // int solve(int row,int col,vector<vector<int>> mat,vector<vector<int>> &dp){

    //     if(col<0 or col>=mat[0].size()) return 1e8;

    //     if(row==0) return mat[row][col];

    //     if(dp[row][col]!=-1) return dp[row][col];
        
    //     int rc=mat[row][col]+solve(row-1,col-1,mat,dp);
    //     int rcc=mat[row][col]+solve(row-1,col,mat,dp);
    //     int rcr=mat[row][col]+solve(row-1,col+1,mat,dp);

    //     return dp[row][col]=min(rc,min(rcc,rcr));

    // }

    int solvetab(vector<vector<int>> mat,vector<vector<int>> &dp){

        for(int i=0;i<mat[0].size();i++){
            dp[0][i]=mat[0][i];
        }

        for(int i=1;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                
                int rc=mat[i][j];
                int rcc=mat[i][j];
                int rcr=mat[i][j]+dp[i-1][j];

                if(j-1>=0) rc+=dp[i-1][j-1];
                else rc+=1e8;

                if(j+1<mat[0].size()) rcc+=dp[i-1][j+1];
                else rcc+=1e8;


                dp[i][j]=min(rc,min(rcc,rcr));
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<mat[0].size();i++){
            mn=min(mn,dp[mat.size()-1][i]);
        }

        return mn;

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,0));
    
        ans=solvetab(matrix,dp);

        return ans;

    }
};