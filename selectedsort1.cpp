#include <iostream>
using namespace std;

void bay(int nums[],int n){
    for(int i=0;i<n-1;i++){
            int u=i;
        for (int j=i+1;j<n;j++){
            if (nums[j]<nums[u]){
                 u=j;
            }
        }
        if(i!=u){
                int temp=nums[i];
                nums[i]=nums[u];
                nums[u]=temp;
        }

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
