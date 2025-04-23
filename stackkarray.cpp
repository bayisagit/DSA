#include <iostream>
using namespace std;
class Bayis{
    int top;
    int* nums;
    int sizus;
public:
    Bayis(int n) {
        top = -1;
        sizus=n;
        nums=new int[sizus];
        }
    bool push(int x){
        if(top>=sizus-1){
            cout<<"the stack is overflow"<<endl;
            return false;
        }
        else{
            nums[++top]=x;
            cout<<"the stack is inserted!"<<endl;
            return true;
        }
    }
    int pop(){
        if(top<0){
            cout<<"the stack is underflow"<<endl;
            return 0;
        }
        else{
            return nums[top--];
        }
    }
    int peeks(){
        if(top<0){
            cout<<"stack is empty!"<<endl;
            return 0;
        }
        else{
            return nums[top];
        }
    }
    bool isempty(){
        return (top<0);
    }
    void display(){
        if(isempty()){
            cout<<"the stack is empty!"<<endl;
            return;
        }
        for(int i=top;i>=0;i--){
            cout<<nums[i]<<" -> ";
        }
        cout<<"null"<<endl;
    }
};
int main(){
    int n;
    cout<<"what is the size of your list: ";
    cin>>n;
    Bayis nums(n);
    nums.push(4);
    nums.push(5);
    nums.push(6);
    cout<<nums.pop()<<" is popped from the stack!"<<endl;
    cout<<"top element is "<<nums.peeks()<<endl;
    cout<<"elements present in stack is ";
    nums.display();

    return 0;
}