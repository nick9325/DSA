class Solution {
    
private:
    bool bfs(int n,vector<int> adj[],vector<int> &col){
        col[n]=0;
        queue<int> q;
	    q.push(n);
	    while(!q.empty()){
	        
	        int node=q.front();
	        q.pop();
	        
	        
	        for(auto x:adj[node]){
                if(col[x]==-1){
                    q.push(x);
                    col[x]=!col[node];
                }
                else if(col[x]==col[node]) return false;
	        }
	        
	    }
	    
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> col(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(col[i]==-1){
	            if(bfs(i,adj,col)==false) return false;
	        }
	    }
	    
	    return true;
	    
	}
};