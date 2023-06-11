class Solution {
public:

    double myPow(double x, int n) {


        //approach 1
        double ans=1.0;

        for(int i=1;i<=abs(n/2);i++){
            ans*=x;
        }

        if(n%2==0){
            ans=ans*ans;
        }
        else{
            ans=ans*ans*x;
        } 
        if(n<0){
            return (double) 1/ans;
        }
        
        return (double) ans;  


        //Approach 2 T=log(n)


        double ans=1.0;
        long long nn=abs(n);

        while(nn){
            if(nn%2!=0){
                ans*=x;
                nn-=1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }

        if(n<0){
            return (double) 1/ans;
        }
        
        return (double) ans;  


    //by using recursion 

        if(n==0){
            return 1;
        }

        if(n<0){
            n=abs(n);
            x=1/x;
        }

        return (n%2==0)?myPow(x*x,n/2):x*myPow(x*x,n/2);

        

    }
};