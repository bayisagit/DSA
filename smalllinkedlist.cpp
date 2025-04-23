#include <iostream>
using namespace std;
struct Ele{
    int data;
    Ele* next;
};
class Smalll{
private:
    Ele* head;
public:
    Smalll(){
        head=nullptr;
    }
    void adds(int values){
        Ele* newnode = new Ele();
        newnode->data=values;
        newnode->next=head;
        head=newnode;
    }
    void display(){
        Ele* temp=head;
        while(temp != nullptr){
            cout<<temp->data<<" <- ";
            temp=temp->next;
        }
    }
    ~Smalll(){
        Ele* curent=head;
        while(curent!=nullptr){
            Ele* nextnode=curent->next;
            delete curent;
            curent=nextnode;
        }
    }

};
int main(){
    Smalll nums;
    nums.adds(5);
    nums.adds(7);
    nums.adds(8);
    nums.adds(9);
    nums.display();
    return 0;
}