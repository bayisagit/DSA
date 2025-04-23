#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void showMainMenu() {
    cout << "\n=================== Hospital Management System ===================\n";
    cout << "1. Patient Scheduling\n";
    cout << "2. Medical Record Management\n";
    cout << "3. Billing & Notification\n";
    cout << "4. Exit\n";
    cout << "=================================================================\n";
    cout << "Enter your choice: ";
}

void showPatientSchedulingMenu() {
    cout << "\n=================== Patient Scheduling ===================\n";
    cout << "1. Add Appointment\n";
    cout << "2. View Appointments\n";
    cout << "3. Search Appointments\n";
    cout << "4. Cancel Appointment\n";
    cout << "5. Back to Main Menu\n";
    cout << "==========================================================\n";
    cout << "Enter your choice: ";
}

void showMedicalRecordMenu() {
    cout << "\n=================== Medical Records ===================\n";
    cout << "1. Add Patient Record\n";
    cout << "2. View Patient Records\n";
    cout << "3. Search Patient Record\n";
    cout << "4. Remove Patient Records\n";
    cout << "5. Back to Main Menu\n";
    cout << "=======================================================\n";
    cout << "Enter your choice: ";
}

void showBillingMenu() {
    cout << "\n=================== Billing & Notification ===================\n";
    cout << "1. Generate Billing\n";
    cout << "2. View Bills\n";
    cout << "3. Search Bills\n";
    cout << "4. Send Appointment Reminder\n";
    cout << "5. Back to Main Menu\n";
    cout << "==============================================================\n";
    cout << "Enter your choice: ";
}


struct Appointment {
    string name;
    string doctor;
    string time;
    string date;
    Appointment* next;
};


class AppointmentStack {
private:
    Appointment* top; 

    
    int getLength() {
        int length = 0;
        Appointment* temp = top;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    
    Appointment* getNodeAt(int index) {
        int count = 0;
        Appointment* temp = top;
        while (temp != NULL) {
            if (count == index) return temp;
            count++;
            temp = temp->next;
        }
        return NULL;
    }

    
    void sortAppointments() {
        int length = getLength();
        if (length <= 1) return;

        for (int i = 0; i < length - 1; i++) {
            Appointment* current = top;
            Appointment* next = top->next;

            for (int j = 0; j < length - i - 1; j++) {
                if (current->name > next->name) {
                    swap(current->name, next->name);
                    swap(current->doctor, next->doctor);
                    swap(current->time, next->time);
                }
                current = next;
                next = next->next;
            }
        }
    }

public:
    AppointmentStack() : top(NULL) {}
    
    
    void addAppointment(string name, string doctor, string time, string date) {
        Appointment* newAppointment = new Appointment();
        newAppointment->name = name;
        newAppointment->doctor = doctor;
        newAppointment->time = time;
        newAppointment->date = date;
        newAppointment->next = top;
        top = newAppointment;

        cout << "Appointment added for " << name << " with Dr. " << doctor << " at " << date << " on " << time << ".\n";
    }

    
    void viewAppointments() {
        if (top == NULL) {
            cout << "No appointments available.\n";
            return;
        }
        cout << "\n=================== Appointments ===================\n";
        cout << setw(5) << "Name" << setw(20) << "Doctor" <<setw(20) << "Date"<< setw(15) << "Time\n";
        cout << "-------------------------------------------------\n";
        Appointment* temp = top;
        while (temp != NULL) {
            cout << setw(5)<< temp->name 
                 << setw(20)<< temp->doctor
				 << setw(20)<< temp->date 
                 << setw(15) << temp->time << "\n";
            temp = temp->next;
        }
        cout << "=================================================\n";
    }

    
    void searchAppointment(string name) {
        if (top == NULL) {
            cout << "No appointments available.\n";
            return;
        }
        
        sortAppointments();

        int low = 0, high = getLength() - 1;
        bool found = false;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            Appointment* midNode = getNodeAt(mid);

            if (midNode->name == name) {
                cout << "Appointment Found:\n";
                cout << "Name: " << midNode->name 
                     << ", Doctor: " << midNode->doctor
					 << ", Date: " << midNode->date  
                     << ", Time: " << midNode->time << "\n";
                found = true;
                break;
            } else if (midNode->name < name) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (!found) {
            cout << "No appointment found for " << name << ".\n";
        }
    }

    void cancelAppointment(string name) {
        if (top == NULL) {
            cout << "No appointments available to cancel.\n";
            return;
        }

        Appointment* temp = top;
        Appointment* prev = NULL;

        while (temp != NULL && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "No appointment found for " << name << " to cancel.\n";
            return;
        }

        if (prev == NULL) {
            top = top->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Appointment for " << name << " has been canceled.\n";
    }

    ~AppointmentStack() {
        while (top != NULL) {
            Appointment* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

struct MedicalRecord {
    string name;
    string disease;
    int age;
    string date;
    MedicalRecord* next; 
};

class MedicalRecordQueue {
private:
    MedicalRecord* front; 
    MedicalRecord* rear;  

    void sortedInsert(MedicalRecord*& sorted, MedicalRecord* newNode) {
        if (sorted == NULL || sorted->name >= newNode->name) {
            newNode->next = sorted;
            sorted = newNode;
        } else {
            MedicalRecord* current = sorted;
            while (current->next != NULL && current->next->name < newNode->name) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    
    void sortRecords() {
        if (front == NULL || front->next == NULL) return;

        MedicalRecord* sorted = NULL; 
        MedicalRecord* current = front;

        while (current != NULL) {
            MedicalRecord* next = current->next; 
            sortedInsert(sorted, current);      
            current = next;                     
        }

        front = sorted; 
    }

public:
    MedicalRecordQueue() : front(NULL), rear(NULL) {}

    void addRecord(string name, string disease, int age, string date) {
        MedicalRecord* newRecord = new MedicalRecord();
        newRecord->name = name;
        newRecord->disease = disease;
        newRecord->age = age;
        newRecord->date = date;
        newRecord->next = NULL;

        if (rear == NULL) { 
            front = rear = newRecord;
        } else {
            rear->next = newRecord;
            rear = newRecord;
        }
        cout << "Record added for " << name << " with disease: " << disease << ".\n";
    }

    void viewRecords() {
        if (front == NULL) {
            cout << "No medical records available.\n";
            return;
        }
        cout << "\n=================== Medical Records ===================\n";
        cout << setw(5) << "Name" << setw(20) << "Age" << setw(15) << "Disease" << setw(20) << "Date\n";
        cout << "-------------------------------------------------\n";
        MedicalRecord* temp = front;
        while (temp != NULL) {
            cout << setw(5)<< temp->name 
                 << setw(20)<< temp->age
				 << setw(15) << temp->disease  
                 << setw(15) << temp->date << "\n";
            temp = temp->next;
        }
        cout << "=================================================\n";
    }

    void searchRecord(string name) {
        if (front == NULL) {
            cout << "No medical records available.\n";
            return;
        }

        sortRecords();

        MedicalRecord* start = front;
        MedicalRecord* end = NULL;

        while (start != end) {
            
            MedicalRecord* slow = start;
            MedicalRecord* fast = start;

            while (fast != end && fast->next != end) {
                slow = slow->next;
                fast = fast->next->next;
            }

            
            if (slow->name == name) {
                cout << "Record Found:\n";
                cout << "Name: " << slow->name 
                     << ", Age: " << slow->age
					 << ", Disease: " << slow->disease 
                     << ", Date: " << slow->date << "\n";
                return;
            } else if (slow->name < name) {
                start = slow->next; 
            } else {
                end = slow;
            }
        }

        cout << "No record found for " << name << ".\n";
    }


    void deleteRecord(string name) {
        if (front == NULL) {
            cout << "No medical records available to delete.\n";
            return;
        }

        MedicalRecord* temp = front;
        MedicalRecord* prev = NULL;

        
        while (temp != NULL && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "No record found for " << name << " to delete.\n";
            return;
        }

        
        if (prev == NULL) { 
            front = temp->next;
        } else {
            prev->next = temp->next;
        }

        if (temp == rear) { 
            rear = prev;
        }

        delete temp;
        cout << "Record for " << name << " has been deleted.\n";
    }

    
    ~MedicalRecordQueue() {
        while (front != NULL) {
            MedicalRecord* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

struct BillNode {
    int appointmentID;
    string patientName;
    double billAmount;
    string date;
    BillNode* next;

    BillNode(int id, string name, double amount,string date)
        : appointmentID(id), patientName(name), billAmount(amount),date(date), next(NULL) {}
};

class BillingSystem {
private:
    BillNode* head; 

public:
    BillingSystem() : head(NULL) {}

    
    void generateBill(int appointmentID, string patientName, double billAmount, string date) {
        BillNode* newNode = new BillNode(appointmentID, patientName, billAmount, date);
        
        if (!head) {
            head = newNode;
        } else {
            BillNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Bill generated successfully for " << patientName << "!\n";
    }

    
    void viewBills() const {
        if (!head) {
            cout << "No bills available.\n";
            return;
        }

        cout << "\n=================== All Bills ===================\n";
        cout << setw(15) << "Appointment ID" << setw(20) << "Patient Name" << setw(15) << "Bill Amount" << setw(15) << "Date\n";
        cout << "-------------------------------------------------\n";

        BillNode* temp = head;
        while (temp) {
            cout << setw(5) << temp->appointmentID
                 << setw(20) << temp->patientName
                 << setw(15) << fixed << setprecision(2) << temp->billAmount
                 << setw(15) << fixed << setprecision(2) << temp->date << "\n";
            temp = temp->next;
        }
        cout << "=================================================\n";
    }

    
    void searchBill(string patientName ) const {
        if (!head) {
            cout << "No bills available.\n";
            return;
        }

        BillNode* temp = head;
        while (temp) {
            if (temp->patientName == patientName) {
                cout << "Bill Found:\n";
                cout << "Appointment ID: " << temp->appointmentID << "\n";
                cout << "Patient Name: " << temp->patientName << "\n";
                cout << "Bill Amount: $" << temp->billAmount << "\n";
                cout << "Date: " << fixed << setprecision(2) << temp->date << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "No bill found for: " << patientName << ".\n";
    }
    
    void sendReminder(const string& patientName) const {
        if (!head) {
            cout << "No patients available to send reminders.\n";
            return;
        }

        BillNode* temp = head;
        while (temp) {
            if (temp->patientName == patientName) {
                cout << "Reminder sent successfully to " << patientName << "!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "No patient found with the name \"" << patientName << "\".\n";
    }

    
    ~BillingSystem() {
        BillNode* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main() {
    int choice, choice2;
    AppointmentStack appointments;
    MedicalRecordQueue records;
    BillingSystem billingSystem;
    string name,doctor, appointmentTime ,date,disease;
    int age,id;
    double bill;

    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
        	appointment:
            showPatientSchedulingMenu();
            cin >> choice2;
            if(choice2 == 1) {
            	cout << "Enter Patient name: ";
	            cin.ignore(); 
	            getline(cin, name);
	            cout << "Enter Doctor name: ";
	            getline(cin, doctor);
	            cout << "Enter Appointment Date (e.g., 2024-12-29): ";
	            getline(cin, date);
	            cout << "Enter Appointment time (e.g., 10:00 AM): ";
	            getline(cin, appointmentTime);
	            appointments.addAppointment(name, doctor,appointmentTime,date);
	            goto appointment;
	            break;
			}
			else if (choice2 == 2) {
				appointments.viewAppointments();
				goto appointment;
				break;
			}
			else if(choice2 == 3) {
				cout << "Enter the name to search: ";
	            cin.ignore();
	            getline(cin, name);
	            appointments.searchAppointment(name);
	            goto appointment;
				break;
			}
			else if(choice2 == 4) {
				cout << "Enter the name to cancel appointment: ";
	            cin.ignore();
	            getline(cin, name);
				appointments.cancelAppointment(name);
				goto appointment;
				break;
			}
			else if (choice2 == 5) {
				cout << "Returning to the main menu...\n";
            	break;
			}
			else {
				cout << "Invalid choice. Please try again.\n";
				goto appointment;
				break;
			}
            break;
        case 2:
        	record:
            showMedicalRecordMenu();
            cin >> choice2;
            if(choice2 == 1) {
            	cout << "Enter patient name: ";
	            cin.ignore(); // Clear input buffer
	            getline(cin, name);
	            cout << "Enter disease: ";
	            getline(cin, disease);
	            cout << "Enter age: ";
	            cin >> age;
	            cout << "Enter Date (e.g., 2024-12-29): ";
	            cin.ignore();
	            getline(cin, date);
	            records.addRecord(name, disease, age,date);
	            goto record;
	            break;
			}
			else if (choice2 == 2) {
				records.viewRecords();
				goto record;
            	break;
			}
			else if (choice2 == 3) {
				cout << "Enter the name to search: ";
	            cin.ignore();
	            getline(cin, name);
	            records.searchRecord(name);
	            goto record;
	            break;
			}
			else if (choice2 == 4) {
				cout << "Enter the name to cancel appointment: ";
	            cin.ignore();
	            getline(cin, name);
				records.deleteRecord(name);
				goto record;
            	break;
			}
			else if (choice2 == 5) {
				cout << "Returning to the main menu...\n";
            	break;
			}
			else {
				cout << "Invalid choice. Please try again.\n";
				goto record;
				break;
			}
            break;
        case 3:
        	billing:
            showBillingMenu();
            cin >> choice2;
            if(choice2 == 1) {
            	cout << "Enter patient name: ";
	            cin.ignore(); // Clear input buffer
	            getline(cin, name);
	            cout << "Enter ID: ";
	            cin >> id;
	            cout << "Enter Bill: ";
	            cin >> bill;
	            cout << "Enter Date (e.g., 2024-12-29): ";
	            cin.ignore();
	            getline(cin, date);
	            billingSystem.generateBill(id,name,bill,date);
	            goto billing;
	            break;
			}
			else if (choice2 == 2) {
				billingSystem.viewBills();
				goto billing;
            	break;
			}
			else if (choice2 == 3) {
				cout << "Enter the name to search: ";
	            cin.ignore();
	            getline(cin, name);
	            billingSystem.searchBill(name);
	            goto billing;
	            break;
			}
			else if (choice2 == 4) {
				cout << "Enter the name to search: ";
	            cin.ignore();
	            getline(cin, name);
	            billingSystem.sendReminder(name);
	            goto billing;
            	break;
			}
			else if (choice2 == 5) {
				cout << "Returning to the main menu...\n";
            	break;
			}
			else {
				cout << "Invalid choice. Please try again.\n";
				goto billing;
				break;
			}
            break;
        case 4:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
