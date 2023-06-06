 int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> m;
        
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        vector<pair<int,int>> v;
      
        for(auto x:m){
            v.push_back(make_pair(x.first,x.second));
        }
        
        sort(v.begin(), v.end(), [=](pair<int, int>&a, pair<int, int>&b) {return a.second > b.second;});
      
        int sz=arr.size();
        int cnt=0;
        for(int i=0;i<v.size();i++){
           sz=sz-v[i].second;
            cnt++;
            if(sz<=arr.size()/2){
                return cnt;
            }
        }
      
        return 1;
    }