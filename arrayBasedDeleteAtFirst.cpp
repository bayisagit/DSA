#include <iostream>
using namespace std;
class Arraylist{
private:
    int sizes;
    int* data;
    int currentIndex;
public:
    Arraylist(int sizes){
    sizes=sizes;
    data = new int[sizes];
    currentIndex=0;
    }
    ~Arraylist(){
    delete[] data;
    }
    void add(int index,int value){
        if(index>=0 && index<sizes){
            data[index]=value;
            if(index>=currentIndex){
                currentIndex=index;
            }
        }
        else{
            cout<<"index out of bound. "<<endl;
        }
    }
    void removeCurrent(int index){
        for (int i=index;i<currentIndex;i++){
            data[i] = data[i+1];
        }

    }
    void print(){
        for(int i=0;i<currentIndex;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }


};
int main(){
    Arraylist arr(10);
    arr.add(0,10);
    arr.add(1,11);
    arr.add(2,12);
    arr.removeCurrent(0);
    arr.print();
    return 0;
}


