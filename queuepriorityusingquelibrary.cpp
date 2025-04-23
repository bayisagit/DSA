#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Person {
    string name;
    string gender;

    Person(string n, string g) : name(n), gender(g) {}
};

class GenderPriorityQueue {
public:
    void enqueue(string name, string gender) {
        Person person(name, gender);
        if (gender == "female" || gender == "Female") {
            femaleQueue.push(person);
        } else {
            maleQueue.push(person);
        }
    }

    Person dequeue() {
        if (!femaleQueue.empty()) {
            Person p = femaleQueue.front();
            femaleQueue.pop();
            return p;
        } else if (!maleQueue.empty()) {
            Person p = maleQueue.front();
            maleQueue.pop();
            return p;
        }
        // Return an empty person if both queues are empty
        return Person("", ""); // You can also handle this differently if needed
    }

    bool is_empty() {
        return femaleQueue.empty() && maleQueue.empty();
    }

private:
    queue<Person> femaleQueue;
    queue<Person> maleQueue;
};

int main() {
    GenderPriorityQueue pq;

    pq.enqueue("Abebe", "male");
    pq.enqueue("Alemu", "male");
    pq.enqueue("Aster", "female");
    pq.enqueue("Belay", "male");
    pq.enqueue("Kedir", "male");
    pq.enqueue("Meron", "Female");
    pq.enqueue("Yonas", "male");

    while (!pq.is_empty()) {
        Person data = pq.dequeue();
        if (!data.name.empty()) { // Check if the name is not empty
            cout << "Dequeued: " << data.name << " (" << data.gender << ")" << endl;
        }
    }
    return 0;
}