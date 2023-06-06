class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
      //  Approach 1

        vector<vector<int>> ans;
        ans.push_back({1});
        int i=0;
        vector<int> temp;
        temp.push_back({1});
        
        while(i<numRows-1){
            vector<int> res;
            res.push_back({1});
            int j=1;
            while(j<temp.size()){
                res.push_back({temp[j-1]+temp[j]});
                j++;
            }

            res.push_back({1});
            ans.push_back(res);

            temp=res;
            i++;
    }

    return ans;

    //Approach 2


    vector<vector<int>> ans;


    //Current element = prevElement * (rowNumber - colIndex) / colIndex

    for(int i=1;i<=numRows;i++){

        vector<int> res;
        res.push_back(1);
        int cur=1;

        for(int j=1;j<i;j++){
            res.push_back((cur*(i-j))/j);
            cur=(cur*(i-j))/j;
        }

        ans.push_back(res);

    }
    return ans;



    
    //Approach 3

    vector<vector<int>> ans;

    for(int i=0;i<numRows;i++){
        vector<int> res(i+1,1);
        for(int j=1;j<i;j++){
            res[j]=ans[i-1][j-1]+ans[i-1][j];
        }
        ans.push_back(res);
    }


    }
};