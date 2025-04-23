#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack <int> element;
    int inte=2332;
    int ori=inte;
    while(inte>0){
        element.push(inte%10);
        inte/=10;
    }
    cout<<element.top();
    cout<<endl;
    cout<<element.size();
    cout<<endl;
    bool ispallin = true;
    while(!element.empty()){
        if(element.top() != ori%10){
            ispallin=false;
            break;
        }
        element.pop();
        ori/=10;
        }
    if(ispallin){
    cout<<"the number is palindrome"<<endl;
    }
    else{
        cout<<"the number is not palindrome"<<endl;
    }
    cout<<element.top();
    element.pop();
    
    return 0;
}