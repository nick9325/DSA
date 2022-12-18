class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
        stack<int> q;
        vector<int> res;

        for(int i=t.size()-1;i>=0;i--){
            while(!q.empty() and t[i]>=t[q.top()]){
                q.pop();
            }
            if(q.empty()){
                res.push_back(0);
            }
            else{
                res.push_back(q.top()-i);
            }

            q.push(i);

        }

        reverse(res.begin(),res.end());


        return res;
            
    }
};
