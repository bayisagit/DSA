#include <iostream>
using namespace std;
int binaryinsertion(int nums[],int keys,int l,int r){
    while(l<=r){
    int mid=(l+r)/2;
    if(nums[mid]<keys){
        l=mid+1;
    }
    else{
        r=mid-1;
    }
    }
    return l;
}
void bay(int nums[],int n){
    for (int i=1;i<n;i++){
    int keys=nums[i];
    int l=0;
    int r=i-1;
    int j=binaryinsertion(nums,keys,l,r);
    for(int k=i;k>j;k--){
        nums[k]=nums[k-1];
    }
    nums[j]=keys;
}
}
int main(){
    int n;
    cout<<"how many numbers: ";
    cin>>n;
    int nums[n];
    cout<<"enter those numbers: ";
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    bay(nums,n);
    cout<<"sorted elements: ";
    for (int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}
