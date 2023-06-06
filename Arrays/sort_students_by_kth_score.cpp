class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        vector<pair<int,int>> scoreinkth;
        vector<vector<int>> ans;
        for(int i=0;i<score.size();i++){
            scoreinkth.push_back({score[i][k],i});
        }
        
        sort(scoreinkth.begin(),scoreinkth.end(),greater<>());
        
        for(auto x:scoreinkth){
            ans.push_back(score[x.second]);
        }
        
        return ans;
    }
};