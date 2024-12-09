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
        data=new int [sizes];
        currentIndex=0;
    }
    ~Arraylist(){
        delete[] data;
    }
    void add(int index,int value){
        if(index>=0 && index<sizes){
            data[index+1]=value;

        if(index>=currentIndex){
            currentIndex=index+1;
        }
        }

    }
    void appendAtFirst(int value){
        data[0]=value;

    }
    void print(){
        for(int i=0;i<=currentIndex;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
    Arraylist arr(10);
    arr.add(0,4);
    arr.add(1,7);
    arr.add(2,9);
    arr.appendAtFirst(20);
    arr.print();
    return 0;
}

