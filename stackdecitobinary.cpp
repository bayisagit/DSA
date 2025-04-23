#include <iostream>
#include <stack>
using namespace std;
void dectob(int nu){
    stack<int> bina;
    while(nu>0){
        int k=nu%2;
        bina.push(k);
        nu/=2;
    }
    while(!bina.empty()){
        cout<<bina.top();
        bina.pop();
    }
}
int main(){
    int nu;
    cout<<"enter the number: ";
    cin>>nu;
    dectob(nu);
    return 0;
}