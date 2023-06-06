class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int start=0,tank=0,tot_gas=0,tot_cost=0;
        for(int i=0;i<n;i++){
            tot_gas+=gas[i];
            tot_cost+=cost[i];

            tank+=gas[i]-cost[i];

            if(tank<0){
                start=i+1;
                tank=0;
            }
        }

        if(tot_gas<tot_cost) return -1;

        return start;


    }
};

// class Solution {
// public:
//     bool solve(int i,int j,vector<int>& gas, vector<int>& cost,int tank){
//         if(tank<cost[i]) return false;

//         if(j==gas.size()-1) return true;

//         tank=tank-cost[i];

//         if(i+1>=gas.size()-1){
//             tank+=gas[(i+1)%gas.size()];
//         }
//         else{
//             tank+=gas[i+1];
//         }
//         return solve((i+1)%gas.size(),j+1,gas,cost,tank);
//     }
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n=gas.size();
//         for(int i=0;i<n;i++){
//             if(gas[i]>=cost[i]){
//                 if(solve(i,0,gas,cost,gas[i])) return i;
//             }
//         }
//         return -1;
//     }
// };