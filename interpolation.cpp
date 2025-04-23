#include <iostream>
using namespace std;

class Interpolation
{
    int Key;
    int Low, High, Mid;

public:
    void InterSearch(int*, int);
};

void Interpolation::InterSearch(int *Arr, int No)
{
    Low = 0;
    High = No - 1;

    cout << "\nEnter the Number to be searched: ";
    cin >> Key;

    while (Low <= High)
    {
        if (Arr[High] == Arr[Low]) {
            if (Arr[Low] == Key) {
                cout << "\nThe key " << Key << " is found at location " << Low << endl;
                return;
            }
            break;
        }

        Mid = Low + (High - Low) * ((Key - Arr[Low]) / (Arr[High] - Arr[Low]));

        if (Key < Arr[Mid])
            High = Mid - 1;
        else if (Key > Arr[Mid])
            Low = Mid + 1;
        else {
            cout << "\nThe key " << Key << " is found at location " << Mid << endl;
            return;
        }
    }

    cout << "\nThe Key " << Key << " is NOT found" << endl;
}

int main()
{
    int *a, n;

    Interpolation Ob;

    cout << "\nEnter the number of elements: ";
    cin >> n;

    a = new int[n];

    cout << "\nEnter the elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Ob.InterSearch(a, n);

    delete[] a;
    return 0;
}
