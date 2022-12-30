class Solution {
public:
    void solve(int s,int n,vector<vector<int>> &ans,vector<vector<int>> g,vector<int> res){
        if(s==n-1){
            res.push_back(s);
            ans.push_back(res);
            return;
        }
        res.push_back(s);
        for(auto x:g[s]){
            solve(x,n,ans,g,res);
        }
        res.pop_back();
            
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> ans;
        vector<int> res;
        solve(0,graph.size(),ans,graph,res);

        return ans;
    }
};