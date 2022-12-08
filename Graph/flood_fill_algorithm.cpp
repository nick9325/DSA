class Solution {
private:

    void dfs(int row,int col,int newcol,vector<vector<int>>& image,int dr[],int dc[],vector<vector<int>>&vis){
        
        vis[row][col]=newcol;
        
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];

            if(nr>=0 and nr<image.size() and nc>=0 and nc<image[0].size() and vis[nr][nc]!=newcol and image[nr][nc]==image[row][col]){
                dfs(nr,nc,newcol,image,dr,dc,vis);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> vis=image;
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        dfs(sr,sc,newColor,image,dr,dc,vis);
        
        return vis;
    }
};