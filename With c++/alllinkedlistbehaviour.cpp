#include <iostream>
#include <string>

using namespace std;

// Define the structure for a single linked list node
struct Student {
    string name;
    int id;
    int age;
    string department;
    Student* next;
};

// Define the structure for a double linked list node
struct DoubleStudent {
    string name;
    int id;
    int age;
    string department;
    DoubleStudent* next;
    DoubleStudent* prev;
};

// Function declarations for single linked list
void addStudentSingle(Student*& head);
void deleteStudentSingle(Student*& head);
void displayStudentsSingle(Student* head);
Student* searchStudentSingle(Student* head, int id);

// Function declarations for double linked list
void addStudentDouble(DoubleStudent*& head);
void deleteStudentDouble(DoubleStudent*& head);
void displayStudentsDouble(DoubleStudent* head);
DoubleStudent* searchStudentDouble(DoubleStudent* head, int id);

// Main function
int main() {
    Student* singleHead = nullptr;
    DoubleStudent* doubleHead = nullptr;
    int choice;

    do {
        cout << "\n1. Single Linked List Operations\n";
        cout << "2. Double Linked List Operations\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Single Linked List:\n";
                int singleChoice;
                cout << "1. Add Student\n2. Delete Student\n3. Display Students\n4. Search Student\n";
                cout << "Enter choice: ";
                cin >> singleChoice;
                switch (singleChoice) {
                    case 1: addStudentSingle(singleHead); break;
                    case 2: deleteStudentSingle(singleHead); break;
                    case 3: displayStudentsSingle(singleHead); break;
                    case 4: {
                        int searchId;
                        cout << "Enter ID to search: ";
                        cin >> searchId;
                        Student* found = searchStudentSingle(singleHead, searchId);
                        if (found) {
                            cout << "Student found: " << found->name << ", ID: " << found->id << ", Age: " << found->age << ", Department: " << found->department << endl;
                        } else {
                            cout << "Student not found." << endl;
                        }
                        break;
                    }
                    default: cout << "Invalid choice." << endl;
                }
                break;

            case 2:
                cout << "Double Linked List:\n";
                int doubleChoice;
                cout << "1. Add Student\n2. Delete Student\n3. Display Students\n4. Search Student\n";
                cout << "Enter choice: ";
                cin >> doubleChoice;
                switch (doubleChoice) {
                    case 1: addStudentDouble(doubleHead); break;
                    case 2: deleteStudentDouble(doubleHead); break;
                    case 3: displayStudentsDouble(doubleHead); break;
                    case 4: {
                        int searchId;
                        cout << "Enter ID to search: ";
                        cin >> searchId;
                        DoubleStudent* found = searchStudentDouble(doubleHead, searchId);
                        if (found) {
                            cout << "Student found: " << found->name << ", ID: " << found->id << ", Age: " << found->age << ", Department: " << found->department << endl;
                        } else {
                            cout << "Student not found." << endl;
                        }
                        break;
                    }
                    default: cout << "Invalid choice." << endl;
                }
                break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}

// Add student to single linked list
void addStudentSingle(Student*& head) {
    Student* newStudent = new Student;
    cout << "Enter Name: ";
    cin >> newStudent->name;
    cout << "Enter ID: ";
    cin >> newStudent->id;
    cout << "Enter Age: ";
    cin >> newStudent->age;
    cout << "Enter Department: ";
    cin >> newStudent->department;
    newStudent->next = nullptr;

    if (head == nullptr) {
        head = newStudent; // First student
    } else {
        cout << "Add at (1) Front, (2) Middle, (3) Last: ";
        int position;
        cin >> position;

        if (position == 1) { // Add to front
            newStudent->next = head;
            head = newStudent;
        } else if (position == 2) { // Add to middle
            Student* temp = head;
            int count = 0;
            while (temp->next != nullptr && count < (1)) {
                count++;
                temp = temp->next;
            }
            newStudent->next = temp->next;
            temp->next = newStudent;
        } else { // Add to last
            Student* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
    }
}

// Delete student from single linked list
void deleteStudentSingle(Student*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Delete (1) First, (2) Last, (3) Middle: ";
    int position;
    cin >> position;

    if (position == 1) { // Delete first
        Student* temp = head;
        head = head->next;
        delete temp;
    } else if (position == 2) { // Delete last
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Student* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    } else { // Delete middle
        cout << "Enter ID of student to delete: ";
        int id;
        cin >> id;

        Student* temp = head;
        Student* prev = nullptr;
        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found." << endl;
            return;
        }

        if (prev == nullptr) { // Deleting the head
            head = head->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
}

// Display all students in single linked list
void displayStudentsSingle(Student* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Student* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", ID: " << temp->id << ", Age: " << temp->age << ", Department: " << temp->department << endl;
        temp = temp->next;
    }
}

// Search for a student in single linked list
Student* searchStudentSingle(Student* head, int id) {
    Student* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            return temp; // Student found
        }
        temp = temp->next;
    }
    return nullptr; // Student not found
}

// Add student to double linked list
void addStudentDouble(DoubleStudent*& head) {
    DoubleStudent* newStudent = new DoubleStudent;
    cout << "Enter Name: ";
    cin >> newStudent->name;
    cout << "Enter ID: ";
    cin >> newStudent->id;
    cout << "Enter Age: ";
    cin >> newStudent->age;
    cout << "Enter Department: ";
    cin >> newStudent->department;
    newStudent->next = nullptr;
    newStudent->prev = nullptr;

    if (head == nullptr) {
        head = newStudent; // First student
    } else {
        cout << "Add at (1) Front, (2) Middle, (3) Last: ";
        int position;
        cin >> position;

        if (position == 1) { // Add to front
            newStudent->next = head;
            head->prev = newStudent;
            head = newStudent;
        } else if (position == 2) { // Add to middle
            DoubleStudent* temp = head;
            int count = 0;
            while (temp->next != nullptr && count < (1)) {
                count++;
                temp = temp->next;
            }
            newStudent->next = temp->next;
            newStudent->prev = temp;

            if (temp->next != nullptr) {
                temp->next->prev = newStudent;
            }
            temp->next = newStudent;
        } else { // Add to last
            DoubleStudent* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStudent;
            newStudent->prev = temp;
        }
    }
}

// Delete student from double linked list
void deleteStudentDouble(DoubleStudent*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Delete (1) First, (2) Last, (3) Middle: ";
    int position;
    cin >> position;

    if (position == 1) { // Delete first
        DoubleStudent* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    } else if (position == 2) { // Delete last
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            DoubleStudent* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->prev->next = nullptr;
            delete temp;
        }
    } else { // Delete middle
        cout << "Enter ID of student to delete: ";
        int id;
        cin >> id;

        DoubleStudent* temp = head;
        while (temp != nullptr && temp->id != id) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found." << endl;
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
}

// Display all students in double linked list
void displayStudentsDouble(DoubleStudent* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    DoubleStudent* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", ID: " << temp->id << ", Age: " << temp->age << ", Department: " << temp->department << endl;
        temp = temp->next;
    }
}

// Search for a student in double linked list
DoubleStudent* searchStudentDouble(DoubleStudent* head, int id) {
    DoubleStudent* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            return temp; // Student found
        }
        temp = temp->next;
    }
    return nullptr; // Student not found
}
