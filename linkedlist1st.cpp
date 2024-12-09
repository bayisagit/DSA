#include <iostream>
using namespace std;
class linkedList{
private:
    struct Node{
    int data;
    Node* next;
    };
    Node* head;
public:
    linkedList(): head(nullptr){}
    void append(int value){
        Node* newNode=new Node;
        newNode->data =value;
        newNode->next=nullptr;
        if(!head){
           head = newNode;
        }
        else{
            Node* lastNode=head;
            while(lastNode->next){
                lastNode=lastNode->next;
            }
            lastNode->next=newNode;
        }

    }
    void display(){
        Node* currentNode=head;
        while(currentNode){
            cout<<currentNode->data<<"->";
            currentNode=currentNode->next;
        }
        cout<<"nullptr"<<endl;

    }
        void deleteNode(int value){
            Node* currentNode = head;
            Node* prevNode = nullptr;
            if(currentNode && currentNode->data == value){
                head=currentNode->next;
                delete currentNode;
                return;
            }
            while(currentNode && currentNode->data != value){
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            if(!currentNode){
                return;
            }
            prevNode->next = currentNode->next;
            delete currentNode;
        }

    ~linkedList(){
        Node* currentNode = head;
        while(currentNode){
            Node* nextNode = currentNode->next;
            delete currentNode;
            currentNode=nextNode;
        }
    }

};
int main(){
    cout<<"hello"<<endl;
    linkedList arr;
    arr.append(10);
    arr.append(20);
    arr.append(30);
    cout<<"Linked list: ";
    arr.display();
    arr.deleteNode(20);
    arr.display();
    return 0;
}
