class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
            cout<<nums[i]<<endl;
        }

        for(int i=0;i<queries.size();i++){
            int l=upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            res.push_back(l);
        }

        return res;
    }
};