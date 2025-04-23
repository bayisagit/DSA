#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* rear;
    Node* front;
};
class Bays{
private:
    Node* head;
    Node* tail;
public:
    Bays(){
        head=nullptr;
        tail=nullptr;
    }
    ~Bays(){
        Node* current=head;
        while (current!=nullptr){
            Node* nextnode=current->rear;
            delete current;
            current=nextnode;
        }
    }
    void enqueue(int values){
        Node* newnode=new Node();
        newnode->data=values;
        newnode->rear=nullptr;
        newnode->front=tail;
        if(tail!=nullptr){
            tail->rear=newnode;
        }
        tail=newnode;
        if(head==nullptr){
            head=newnode;
        }
    }
    void display(){
        Node* temp=head;
        while(temp!=nullptr){
           cout<<temp->data;
           temp=temp->rear;
        }
    }
};
int main(){
    Bays s;
    s.enqueue(3);
    s.enqueue(9);
    s.enqueue(12);
    s.display();
    return 0;
}