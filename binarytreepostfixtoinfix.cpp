#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* l;
    Node* r;
    Node(int value){
        data=value;
        l=nullptr;
        r=nullptr;
    }
};
class Btre{
public:
    Node* root =nullptr;
    Btre(){
        root=nullptr;
    }
    Node* inserts(Node* node,int value){
        if(node == nullptr){
            return new Node(value);
        }
        else{
            if (value<node->data){
                inserts(node->l,value);
            }
            else{
                inserts(node->r,value);
            }
        }
        return node;
    }
    void insert(int value){
        root=inserts(root,value);
    }

};

int main(){
    Btre bt;
    bt.insert(3);
    bt.insert(4);
    return 0;
}