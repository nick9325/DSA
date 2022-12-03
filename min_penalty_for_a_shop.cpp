class Solution {
public:
    int bestClosingTime(string c) {
        
        // int cnty=0;
        // int cntn=0;
        
        // for(int i=0;i<c.length();i++){
        //     if(c[i]=='Y'){
        //         cnty++;
        //     }
        //     else{
        //         cntn++;
        //     }
        // }
        // if(cnty==0) return 0;
        // if(cntn==0) return c.length();
        // if(c.length()==1 and c[0]=='Y') return 1;
        // if(c.length()==1 and c[0]=='N') return 0;
        // int res=cnty,ans=0,cc=cnty;
        // for(int i=1;i<=c.length();i++){
            
        //     if(c[i-1]=='Y'){
        //         res--;
        //     }
        //     else{
        //         res++;
        //     }
        //     if(res<cc){
        //         ans=i;
        //         cc=res;
        //     }
        // }
        // return ans;

        int ans=-1;
        int res=0;
        int sc=0;
        for(int i=0;i<c.length();i++){
            if(c[i]=='Y') res++;
            else res--;

            if(res>sc){
                res=sc;
                ans=i;
            }
        }

        return ans+1;
    }
};