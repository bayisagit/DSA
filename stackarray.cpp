#include <iostream>
using namespace std;

int top = -1;

void push(int list[], int maxx)
{
    if (top == maxx - 1)
        cout << "stack is full";
    else
    {
        ++top;
        cin >> list[top];
    }
}

void pop(int list[])
{
    if (top == -1)
        cout << "Stack underflow";
    else
    {
        int pp = list[top];
        --top;
        cout << pp << " has been deleted";
    }
}
void peek(int list[])
{
    if (top == -1)
        cout << "Stack underflow";
    //  --top;
    else
        cout << list[top] << " is the last stack element";
}
void display(int list[])
{
    if (top == -1)
        cout << "Stack underflow";
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << list[i] << " ";
        }
    }
}

int main()
{
start:
    int x, maxx;
    cout << "what is the maximum number of elements? ";
    cin >> maxx;
    if (0 >= maxx)
    {
        cout << "ERROR ERROR WRONG SIZE!!!!!!!!";
        goto start;
    }
    cout << "how many elements does the array have? ";
    cin >> x;
    if (x > maxx)
    {
        cout << "ERROR ERROR WRONG SIZE!!!!!!!!";
        goto start;
    }
    int *list = new int[maxx];
    for (int i = 0; i < x; i++)
    {
        cout << "enter element" << i + 1 << ": ";
        //   cin >> list[i];
        push(list, maxx);
    }
    do
    {
        int MM;
        cout << "\nMain Menu:\n1)push\n2)pop\n3)peek\n4)display\n5)exit"<<endl;
        cin >> MM;
        if (MM == 1)
        {
            cout << "enter the number:";
            push(list, maxx);
        }
        else if (MM == 2)

            pop(list);

        else if (MM == 3)
        {
            peek(list);
        }
        else if (MM == 4)
        {
            display(list);
        }
        else if (MM == 5)
        {
            return 0;
        }
        else
            cout << "\ninvalid choice!!!!";
    } while (true);
}
