#include <iostream>
using namespace std;
class Alist{
private:
    int* data;
    int sizes;
    int currentIndex;
public:
    Alist(int sizes){
    sizes=sizes;
    data=new int[sizes];
    currentIndex=0;
    }
    ~Alist(){
    delete[] data;
    }
    void add(int index,int value){
    if(index >= 0  && index<sizes){
        data[index] = value;
    }
    else {
        cout<<"index out of bounds."<<endl;
    }
    }
    void setCurrentIndex(int index){
    if(index >=0 && index<sizes){
       currentIndex=index;
       }else{
       cout<<"index out of bounds."<<endl;
       }
    }
    int getCurrentValue(){
    return data[currentIndex];
    }
    };
int main(){
    Alist lis(10);
    lis.add(0,5);
    lis.add(1,10);
    lis.setCurrentIndex(1);
    cout<<"Current Value: "<<lis.getCurrentValue()<<endl;

    return 0;
}
