class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


        //T=O(nlogn)+O(n) S=O(n)->to store ans

        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int minI=intervals[0][0],maxI=intervals[0][1];

        for(auto x:intervals){
            if(x[0]>maxI){
                ans.push_back({minI,maxI});
                minI=x[0];
                maxI=x[1];
            }
            else{
                maxI=max(maxI,x[1]);
            }
          
        }
        
        ans.push_back({minI,maxI});

        return ans;


        //using temp array intead of vars

        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];

        for(auto x:intervals){
            if(x[0]>temp[1]){
                ans.push_back(temp);
                temp=x;
            }
            else{
                temp[1]=max(temp[1],x[1]);
            }
        }
        ans.push_back(temp);

        return ans;


    }
};