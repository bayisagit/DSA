#include <iostream>
using namespace std;
int binaryin(int keys,int l,int r,int nums[]){
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
void bay(int n,int nums[]){
    for (int i=0;i<n;i++){
        int keys=nums[i];
        int l=0;
        int r=i-1;
        int val=binaryin(keys,l,r,nums);
        for(int k=i;k>val;k--){
            nums[k]=nums[k-1];
        }
        nums[val]=keys;
    }
}
int main(){
    int n=4;
    int nums[]= {6,2,1,7};
    bay(n,nums);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}
