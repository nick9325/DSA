class NumArray {
public:
    vector<int> res;
    int sum=0;
    NumArray(vector<int>& nums) {
            res=nums;
        
        for(int i=0;i<nums.size();i++){
            sum+=res[i];
        }
    }
    
    void update(int index, int val) {
        sum-=res[index];
        res[index]=val;
        sum+=val;
    }
    
    int sumRange(int left, int right) {
        int r=sum;
        for(int i=0;i<left;i++){
            r-=res[i];
        }
        for(int i=right+1;i<res.size();i++){
            r-=res[i];
        }
        return r;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */