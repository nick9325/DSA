class Solution {
    
private:
    bool bfs(int n,vector<int> adj[],int c,vector<int> &col){
        col[n]=c;
	   
	    for(auto x:adj[n]){
	        if(col[x]==-1){
	            if(bfs(x,adj,!c,col)==false)    return false;
	        }
	        else if(col[x]==c) {
	            return false;
	        }
	    }
	    
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> col(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(col[i]==-1){
	            if(bfs(i,adj,0,col)==false) return false;
	        }
	    }
	    
	    return true;
	    
	}
};