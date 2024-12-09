#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int>numstack;
    numstack.push(2);
    numstack.push(3);
    numstack.push(4);
    if (numstack.empty()){
        cout<<"the stack is empty"<<endl;
    }
    else{
        cout<<"the stack is not empty"<<endl;
    }
    cout<<"remove "<<numstack.top()<<endl;
    numstack.pop();
    cout<<"the size of stack is "<<numstack.size()<<endl;
    return 0;
}
