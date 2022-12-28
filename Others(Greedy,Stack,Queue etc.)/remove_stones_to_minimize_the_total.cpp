class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> q;

        for(int i=0;i<piles.size();i++){
            q.push(piles[i]);
        }

        while(!q.empty() and k>0){
            int top=q.top();
            q.pop();
            top-=floor(top/2);
            q.push(top);
            k--;
        }

        int ans=0;
        while(!q.empty()){
            ans+=q.top();
            q.pop();
        }

        return ans;
    }
};