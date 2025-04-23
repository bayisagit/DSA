#include <iostream>
using namespace std;
int top = -1;
void pushs(int nums[],int sizus,int numb){
    if(top>=sizus-1){
        cout<<"stack is overflow"<<endl;
    }
    else{
        ++top;
        nums[top]=numb;
        cout<<"item inserted succesfully"<<endl;
    }
}
void display(int nums[]){
    for(int i=0;i<=top;i++){
        cout<<nums[i]<<" -> ";
    }
}
int main(){
    int sizu;
    cout<<"enter the size of the array: ";
    cin>>sizu;
    int nums[sizu];
    int nu;
    cout<<"enter how many number you want to enter: ";
    cin>>nu;
    for(int i=0;i<nu;i++){
        int numb;
        cin>>numb;
    pushs(nums, sizu, numb);
    }
    display(nums);
    return 0;
}