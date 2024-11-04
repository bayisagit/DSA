#include <iostream>
#include <array>
using namespace std;

void bay(int nums[],int n){
    for(int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (nums[j]<nums[i]){
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
            }
        }
    }
}

int main(){
    int n;
    cout<<"please enter how many number would you want to enter: ";
    cin>>n;
   int nums[n];
   for (int i=0;i<n;i++){
    cin>>nums[i];
   }
   bay(nums,n);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;

}
