class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }

        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;

        q.push({0,{0,src}});
        //{stops,{cost,node}}
        dist[src]=0;
        while(!q.empty()){

            int node=q.front().second.second;
            int cost=q.front().second.first;
            int stops=q.front().first;
            q.pop();

            if(stops>k) continue;

            for(auto x:adj[node]){
                if(dist[x.first]>cost+x.second and stops<=k){
                    dist[x.first]=cost+x.second;
                    q.push({stops+1,{cost+x.second,x.first}});
                }
            }

        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};