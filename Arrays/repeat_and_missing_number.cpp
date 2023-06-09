#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Approach 1 

    pair<int,int> p;
    int mp[n+1]={0};

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    int repeating=-1,missing=-1;
    for(int i=1;i<=n;i++){
        if(mp[i]==2){
            repeating=i;
        }
        else if(mp[i]==0){
            missing=i;
        }
        
        if(repeating!=-1 and missing!=-1) break;
    }
    
    p.second=repeating;
    p.first=missing;

    return p;



    //Approach 2


    pair<int,int> p;


    long long sn=n*(n+1)/2;
    long long s2n=(n*(n+1)*(2*n+1))/6;

    long long s=0,s2=0;

    for(int i=0;i<n;i++){
        s+=arr[i];
        s2+=(long long)arr[i] * (long long)arr[i];
    }


    long val1=s-sn;
    long val2=(s2-s2n)/val1;


    int x=(val1+val2)/2;
    int y=x-val1;


    p.second=x;
    p.first=y;

    return p;



    //Approach 3
    	int m, r;
	
	// traversing the array 
	for(int i = 0; i < n; i += 1)
	{
		if( arr[abs(arr[i]) - 1] > 0 )
		{
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
		}
		// if arr[i] is already negative, it is the repeating number
		else  		
		{
			r = abs(arr[i]);
		}
	}
	
	
	for(int i = 0; i < n; i += 1)
	{
		// the index at which the element is positive is the missing number 
		if( arr[i] > 0 )
		{
			m = i + 1;
			break;
		}
	}
	
	pair<int, int>ans;
	
	ans.first = m;
	ans.second = r;
	
	return ans;
	
}
