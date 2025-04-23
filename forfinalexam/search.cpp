#include <iostream>
using namespace std;
int main(){
    int val;
    int n;
    cout<<"enter the number of arrays: ";
    cin>>n;
    cout<<"enter the value you want search:";
    cin>>val;
    int nums[n]={2,4,8,1,9};
    for (int i=0;i<n;i++){
        if (nums[i]==val){
            cout<<"yes";
            break;
        }
    }
    return 0;
}