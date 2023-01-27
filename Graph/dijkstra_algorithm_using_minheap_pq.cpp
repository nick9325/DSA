class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> res(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        
        q.push({0,S});
        res[S]=0;
        while(!q.empty()){
            
            int node=q.top().second;
            int dist=q.top().first;
            q.pop();
            
            for(auto x:adj[node]){
                if(res[x[0]]>dist+x[1]){
                    res[x[0]]=dist+x[1];
                    q.push({dist+x[1],x[0]});
                }
            }
        }
        
        return res;
        
        
    }
};