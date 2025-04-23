#include <iostream>
using namespace std;
class Arraylu {
private:
    int sizes;
    int* data;
    int currentindex;
public:
   Arraylu(int sizes){
       this->sizes=sizes;
       data=new int[sizes];
       currentindex=0;
   }
   ~Arraylu(){
    delete [] data;
   }
   void add(int indes,int value){
    if(indes>=0 && indes<sizes){
        if(currentindex>=sizes){
            cout<<"out of bound!"<<endl;
            return;
        }
    for(int i=currentindex;i>indes;i--){
        data[i]=data[i-1];
    }
    data[indes]=value;
    currentindex+=1;
   }
    else {
        cout<<"out of bound";
        return;
    }
   }
   void display(){
       for(int i=0;i<currentindex;i++){
        cout<<data[i]<<" ";
       }
       cout<<endl;
   }

};
int main(){
    int sizes;
    cout<<"enter the sizes: ";
    cin>>sizes;
    Arraylu nums(sizes);
    for(int i=0;i<sizes;i++){
        int values;
        cin>>values;
        nums.add(i,values);
    }
    cout<<"the element is: ";
    nums.display();
    return 0;
}