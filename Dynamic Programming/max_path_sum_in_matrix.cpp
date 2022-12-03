#include <bits/stdc++.h> 


int solve(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &dp){
   if(j<0 || j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
       
    int s=matrix[i][j]+solve(matrix,i-1,j,dp);
    int ld=matrix[i][j]+solve(matrix,i-1,j-1,dp);
    int rd=matrix[i][j]+solve(matrix,i-1,j+1,dp);
    
    return dp[i][j]=max(s,max(ld,rd)); 
}
int solve2(vector<vector<int>> &matrix,vector<vector<int>> &dp){
    
    for(int j=0;j<matrix[0].size();j++) dp[0][j]=matrix[0][j];
    
    for(int i=1;i<matrix.size();i++){
        
        for(int j=0;j<matrix[0].size();j++){
            
            int s=matrix[i][j]+dp[i-1][j];
            int ld=matrix[i][j];
            if(j-1>=0){
                ld+=dp[i-1][j-1];
            }
            else{
                ld+=-1e8;
            }
            int rd=matrix[i][j];
            if(j+1<matrix[0].size()){
                rd+=dp[i-1][j+1];
            }
            else{
                rd+=-1e8;
            }
            
            dp[i][j]=max(s,max(ld,rd));
        }
        
    }
    int maxi=-1e8;
    
    for(int j=0;j<matrix[0].size();j++){
        maxi=max(maxi,dp[matrix.size()-1][j]);
    }
    
    return maxi;
}

int solve3(vector<vector<int>> &matrix){
    vector<int> prev(matrix[0].size(),0),cur(matrix[0].size(),0);
    for(int j=0;j<matrix[0].size();j++) prev[j]=matrix[0][j];
    
    for(int i=1;i<matrix.size();i++){
        
        for(int j=0;j<matrix[0].size();j++){
            
            int s=matrix[i][j]+prev[j];
            int ld=matrix[i][j];
            if(j-1>=0){
                ld+=prev[j-1];
            }
            else{
                ld+=-1e8;
            }
            int rd=matrix[i][j];
            if(j+1<matrix[0].size()){
                rd+=prev[j+1];
            }
            else{
                rd+=-1e8;
            }
            
            cur[j]=max(s,max(ld,rd));
        }
        prev=cur;
    }
    int maxi=-1e8;
    
    for(int j=0;j<matrix[0].size();j++){
        maxi=max(maxi,prev[j]);
    }
    
    return maxi;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),-1));            
//      int maxi=-1e8;
                           
//     for(int i=0;i<matrix[0].size();i++){
//         maxi=max(maxi,solve(matrix,matrix.size()-1,i,dp));
//     }
    
                          
//     return maxi;
    
//     return solve2(matrix,dp);
    
    return solve3(matrix);
    
    
    
    
}