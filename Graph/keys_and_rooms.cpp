
private:
    void dfs(int s,vector<vector<int>> &r,vector<bool> &vis){

        vis[s]=true;

        for(int i=0;i<r[s].size();i++){
            if(!vis[r[s][i]]){
                dfs(r[s][i],r,vis);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        int m=rooms[0].size();

        vector<bool> vis(n,false);
        dfs(0,rooms,vis);

        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }


        return true;

    }
};