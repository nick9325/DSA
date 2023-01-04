class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(auto x:tasks){
            m[x]++;
        }
        int ans=0,rem=0;
        for(auto x:m){
           int fr=x.second;

           if(fr==1) return -1;
           else if(fr%3==0) ans+=fr/3;
           else{
               ans+=fr/3+1;
           }

        }
        // cout<<(55/3+1)<<endl;
        return ans;
    }
};