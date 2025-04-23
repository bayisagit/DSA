#include <iostream>
using namespace std;

void shellsort(int nums[],int n){
    for(int gap = n/2;gap>0;gap/=2){
        for (int i=gap;i<n;i++){
            int temp=nums[i];
            int j;
            for(j=i;j>=gap && nums[j-gap]>temp;j-=gap){
                nums[j]=nums[j-gap];
            }
            nums[j]=temp;

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
    shellsort(nums,n);
    cout<<"sorted elements: ";
    for (int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;

}

