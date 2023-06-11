#include <bits/stdc++.h> 


long long merge(long long *arr,int s,int mid,int e){
    int right=mid+1;
    int left=s;
    long long inv=0;

    vector<long long> temp;
    
    
    while(left<=mid and right<=e){
        
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            inv+=mid-left+1;
            temp.push_back(arr[right++]);
        }
    }

    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    
    while(right<=e){
        temp.push_back(arr[right++]);
    }

    for(int i=s;i<=e;i++){
        arr[i]=temp[i-s];
    }

    return inv;
    
}

long long mergeSort(long long *arr,int s,int e){
    long long inv=0;
    if(s>=e) return inv;

    int mid=(s+(e-s)/2);
    
    inv+=mergeSort(arr, s, mid);
    inv+=mergeSort(arr,mid+1,e);

    inv+=merge(arr,s,mid,e);

    return inv;
}

long long getInversions(long long *arr, int n){

    return mergeSort(arr,0,n-1);
    
}