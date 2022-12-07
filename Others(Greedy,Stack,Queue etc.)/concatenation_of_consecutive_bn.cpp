int concatenatedBinary(int n) {
        
        int len=0;
        long ans=0;
        long mod=1e9+7;
        for(int i=1;i<=n;i++){
             cout<<"(i&(i-1)): "<<(i&(i-1))<<endl;
            if((i&(i-1))==0){
               
                len++;
            }
            cout<<"len: "<<len<<" ans: "<<ans<<" ans<<len: "<<(ans<<len)<<endl;
            ans=((ans<<len)+i)%mod;
            cout<<"ans: "<<ans<<endl;
        }
        
        return ans;
    }