
bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),cmp);

        int ans=1;
        int xend=points[0][1];
        int i=1;

        for(int i=1;i<points.size();i++){
            if(points[i][0]>xend){
                ans++;
                xend=points[i][1];
            }
        }

        return ans;
    }
};