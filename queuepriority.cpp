#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    string gender;
    Node* next;

    Node(string n, string g) : name(n), gender(g), next(nullptr) {}
};

class PriorityQueue {
public:
    PriorityQueue() : head(nullptr) {}

    void enqueue(string name, string gender) {
        Node* newNode = new Node(name, gender);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    Node* dequeue() {
        if (head == nullptr) return nullptr;

        Node* current = head;
        Node* femalePrev = nullptr;
        Node* femaleNode = nullptr;

        while (current != nullptr) {
            if (current->gender == "female" || current->gender == "Female") {
                femaleNode = current;
                break;
            }
            femalePrev = current;
            current = current->next;
        }

        if (femaleNode != nullptr) {
            if (femalePrev == nullptr) {
                head = femaleNode->next;
            } else {
                femalePrev->next = femaleNode->next;
            }
            return femaleNode;
        }

        Node* temp = head;
        head = head->next;
        return temp;
    }

    bool is_empty() {
        return head == nullptr;
    }

private:
    Node* head;
};

int main() {
    PriorityQueue pq;

    pq.enqueue("Abebe", "male");
    pq.enqueue("Alemu", "male");
    pq.enqueue("Aster", "female");
    pq.enqueue("Belay", "male");
    pq.enqueue("Kedir", "male");
    pq.enqueue("Meron", "Female");
    pq.enqueue("Yonas", "male");

    while (!pq.is_empty()) {
        Node* data = pq.dequeue();
        if (data != nullptr) {
            cout << "Dequeued: " << data->name << " (" << data->gender << ")" << endl;
            delete data;
        }
    }
    return 0;
}