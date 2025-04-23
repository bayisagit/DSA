#include <iostream>
#include <stack>
using namespace std;
bool ispalin(string values){
    stack<char> element;
    for(char ch:values){
       element.push(ch);
    }
    for(int i=0;i<values.size();i++){
        if(element.top() != values[i]){
            return false;
        }
        element.pop();
    }
    return true;
}
int main(){
    stack<string> element;
    string values;
    cout<<"enter the string: ";
    cin>>values;
    if(ispalin(values)){
        cout<<"the string is palindrome"<<endl;
    }
    else{
        cout<<"the string is not palindrome"<<endl;
    }
    return 0;
}