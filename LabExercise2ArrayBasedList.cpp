#include <iostream>
using namespace std;

class Arraylist {
private:
    int sizes;
    int* data;
    int currentIndex;

public:
    Arraylist(int sizes) {
        this->sizes = sizes;
        data = new int[sizes];
        currentIndex = 0;
    }

    ~Arraylist() {
        delete[] data;
    }

    void add(int index, int value) {
        if (index >= 0 && index < sizes) {
            if (currentIndex >= sizes) {
                cout << "Array is full!" << endl;
                return;
            }

            for (int i = currentIndex; i > index; i--) {
                data[i] = data[i - 1];
            }

            data[index] = value;
            currentIndex++;
        } else {
            cout << "Index out of bounds!" << endl;
        }
    }
    void remove(int index) {
        if (index >= 0 && index < currentIndex) {
            for (int i = index; i < currentIndex - 1; i++) {
                data[i] = data[i + 1];
            }
            currentIndex--;
        } else {
            cout << "Invalid index for deletion!" << endl;
        }
    }

    int getValue(int index) {
        if (index >= 0 && index < currentIndex) {
            return data[index];
        }
        return -1;
    }

    void print() {
        for (int i = 0; i < currentIndex; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int getCurrentIndex() const {
        return currentIndex;
    }
};

int main() {
    Arraylist arr(10);
    cout << "Enter the first 4 elements for the sake of program function: ";
    for (int i = 0; i < 4; i++) {
        int value;
        cin >> value;
        arr.add(i, value);
    }

    while (true) {
        int ch;
        cout << "Main Menu" << endl;
        cout << "1 for insertion!" << endl;
        cout << "2 for deletion!" << endl;
        cout << "3 for get value!" << endl;
        cout << "4 for display!" << endl;
        cout << "5 for exit!" << endl;
        cout << "Choose: ";
        cin >> ch;

        if (ch == 1) {
            int cho;
            cout << "1 for insert at the beginning" << endl;
            cout << "2 for insert at any position" << endl;
            cout << "3 for insert at the end" << endl;
            cin >> cho;

            if (cho == 1) {
                int value;
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                arr.add(0, value);
            } else if (cho == 2) {
                int index, value;
                cout << "Enter index and value to insert: ";
                cin >> index >> value;
                arr.add(index, value);
            } else if (cho == 3) {
                int value;
                cout << "Enter value to insert at end: ";
                cin >> value;
                arr.add(arr.getCurrentIndex(), value);
            }
        } else if (ch == 2) {
            int cho;
            cout << "1 for delete at the beginning" << endl;
            cout << "2 for delete at any position" << endl;
            cout << "3 for delete at the end" << endl;
            cin >> cho;

            if (cho == 1) {
                arr.remove(0);
            } else if (cho == 2) {
                int index;
                cout << "Enter index to delete: ";
                cin >> index;
                arr.remove(index);
            } else if (cho == 3) {
                arr.remove(arr.getCurrentIndex() - 1);
            }
        } else if (ch == 3) {
            int index;
            cout << "Enter index to get value: ";
            cin >> index;
            int value = arr.getValue(index);
            if (value != -1) {
                cout << "Value at index " << index << ": " << value << endl;
            } else {
                cout << "Invalid index!" << endl;
            }
        } else if (ch == 4) {
            int cho;
            cout << "1 for display from the beginning to end" << endl;
            cout << "2 for display from the end to beginning" << endl;
            cin >> cho;

            if (cho == 1) {
                arr.print();
            } else if (cho == 2) {
                for (int i = arr.getCurrentIndex() - 1; i >= 0; i--) {
                    cout << arr.getValue(i) << " ";
                }
                cout << endl;
            }
        } else if (ch == 5) {
            cout << "Terminating the main! Good bye!" << endl;
            break;
        } else {
            cout << "The choice you made was incorrect!" << endl;
        }
    }

    return 0;
}
