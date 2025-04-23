#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class Bays{
    Node* top;
public:
    Bays(){
        top=nullptr;
    }
    ~Bays(){
        while(!isempty()){
            pop();
        }
    }
    void push(int x){
        Node* newnode=new Node;
        newnode->data=x;
        newnode->next=top;
        top=newnode;
    }
    int pop(){
        if(top==nullptr){
            cout<<"the stack is underflow"<<endl;
            return 0;
        }
        else{
            int poppeddata=top->data;
            Node* temp=top;
            top=top->next;
            delete temp;
            return poppeddata;
        }
    }
    int peeks(){
        if(top==nullptr){
            cout<<"stack is empty!"<<endl;
            return 0;
        }
        else{
            return top->data;
        }
    }
    bool isempty(){
        return (top==nullptr);
    }
    void display(){
        if(isempty()){
            cout<<"stack is empty!"<<endl;
            return;
        }
        Node* current=top;
        while(current!=nullptr){
            cout<<current->data<<" -> ";
            current=current->next;
        }
        cout<<"null"<<endl;
    }
};
int main(){
    Bays e;
    e.push(4);
    e.push(5);
    e.push(6);
    cout<<e.pop()<<" is popped from the stack!"<<endl;
    cout<<"top element is "<<e.peeks()<<endl;
    cout<<"elements present in stack: ";
    e.display();
    return 0;
}