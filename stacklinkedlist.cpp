#include <iostream>

using namespace std;

struct num
{
    int data;
    num *next;

    num(int datVal)
    {
        data = datVal;
        next = nullptr;
    }
};

struct LinkedList
{
    num *top;

    LinkedList()
    {
        top = nullptr;
    }
    void push(int data)
    {
        num *p = new num(data);
        p->next = top;
        top = p;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        num *temp = top;
        top = top->next;
        cout << temp->data << " has been deleted";
        delete temp;
    }
    void peek()
    {
        if (top == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        cout << " the selected element is:" << top->data;
    }
    void display()
    {
        num *temp = top;
        while (temp != nullptr) // temp->nul
        {
            cout << temp->data << " "; // 4123
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList list;
    int x, data;

    cout << "How many nodes do you want to create? ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        cout << "Enter data" << (i + 1) << ": ";
        cin >> data;
        list.push(data);
    }

    do
    {
        int MM;
        cout << "\nMain Menu:\n1)push\n2)pop\n3)peek\n4)display\n5)exit";
        cin >> MM;
        if (MM == 1)
        {
            cout << "enter the number:";
            cin >> data;
            list.push(data);
        }
        else if (MM == 2)
            list.pop();
        else if (MM == 3)
            list.peek();
        else if (MM == 4)
            list.display();
        else if (MM == 5)
            return 0;
        else
            cout << "\ninvalid choice!!!!";
    } while (true);
}
