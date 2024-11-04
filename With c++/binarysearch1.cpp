#include <iostream>

using namespace std;

bool bay(int nums[],int n,int keys){
    int l=0;
    int r=n-1;
    while (l<r) {
        int mid=(l+r)/2;
        if (nums[mid] == keys){
            return true;
        }
        else if (nums[mid] < keys){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    return false;
}

int main(){
    int n,key;
    cout<<"how many numbers would you want enter: ";
    cin>>n;
    cout<<"enter those numbers: ";
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"enter the key you want find: ";
    cin>>key;
    if(bay(nums,n,key)){
        cout<<"the key "<<key<<"is found in the array elements!";
    }
    else{
        cout<<"the key "<<key<<"is not found in the array elements!";
    }
    return 0;
}

