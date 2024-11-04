#include <iostream>
using namespace std;

void bay(int nums[],int n){
    for(int i=n-1;i>=0;i--){
        for (int j=0;j<i;j++){
            if (nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
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

