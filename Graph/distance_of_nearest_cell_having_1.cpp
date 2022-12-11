class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    
	    int m=grid.size();
	    int n=grid[0].size();
	    
	    vector<vector<int>> vis(m,vector<int>(n,0));
	    vector<vector<int>> dist(m,vector<int>(n,0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	        }
	    }
	    
	    int dirr[]={0,-1,0,1};
	    int dirc[]={1,0,-1,0};
	    
	    while(!q.empty()){
	        
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int d=q.front().second;
	        q.pop();
	        dist[row][col]=d;
	        
	        for(int i=0;i<4;i++){
                int r=row+dirr[i];
                int c=col+dirc[i];
                if(r>=0 and r<m and c>=0 and c<n and vis[r][c]==0){
                    q.push({{r,c},d+1});
                    vis[r][c]=1;
                }
	                
	         }
	        }
	        
	    return dist;
	    
	}
};