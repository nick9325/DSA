class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n =points.size();
        if(n<3)
        return n;

        int ans = 0;

        for(int i=0;i<n;i++){
            unordered_map<double,int> mp;
            int self = 1;
            for(int j=i+1;j<n;j++){
                if(points[i][0] == points[j][0] && points[j][1] == points[i][1])
                self++;
                else if(points[i][0] == points[j][0])
                mp[INT_MAX]++;
                else{
                    double slope = double(points[i][1]-points[j][1])/double(points[i][0]-points[j][0]);
                    mp[slope]++;
                }
            }
            int mx = 0;
            for(auto ele : mp){
                mx = max(mx,ele.second);
            }
            ans = max(ans,mx+self);
        }
        return ans;
    }
};