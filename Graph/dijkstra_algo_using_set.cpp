class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        set<pair<int,int>> st;
        vector<int> res(V,1e9);
        
        st.insert({0,S});
        res[S]=0;
        
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int dist=it.first;
            st.erase(it);
            
            for(auto x:adj[node]){
                if(res[x[0]]>dist+x[1]){
                    if(res[x[0]]!=1e9){
                        st.erase({res[x[0]],x[0]});
                    }
                    res[x[0]]=dist+x[1];
                    st.insert({dist+x[1],x[0]});
                }
            }
        }
        return res;
        
    }
};