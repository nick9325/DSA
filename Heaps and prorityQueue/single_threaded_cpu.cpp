class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        

        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }

         vector<int> res;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;


        sort(tasks.begin(),tasks.end());

        
        long time=tasks[0][0];
        int i=0;
        while(!q.empty() or i<tasks.size()){

            while(i<tasks.size() and tasks[i][0]<=time){
                q.push({tasks[i][1],tasks[i][2]});
                i++;
            }

            if(q.empty()){
                time=tasks[i][0];
            }
            else{
                time+=q.top().first;
                res.push_back(q.top().second);
                q.pop();
            }
        }
        
        return res;
    } 
};