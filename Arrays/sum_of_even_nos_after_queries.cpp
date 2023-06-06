 vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        
        int evenSum=0;
        
        for(auto x:nums){
            if(x%2==0){
                evenSum+=x;
            }
        }
       
        vector<int> ans;
        
        for(int i=0;i<queries.size();i++){
                int numI=nums[queries[i][1]];
            
                if(numI%2==0){
                    evenSum-=numI;
                }
            
                int sum=numI+queries[i][0];
                cout<<sum<<" "<<evenSum<<endl;
                if(abs(sum)%2==0){
                    evenSum+=sum;
                }
                nums[queries[i][1]]=sum;
                ans.push_back(evenSum);
        }
        
        return ans;
        
    }