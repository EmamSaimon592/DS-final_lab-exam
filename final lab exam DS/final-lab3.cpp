/*A Queue is a linear data structure that follows the FIFO (First In, First Out) rule.

    Insertion (enqueue) happens at the rear.

    Deletion (dequeue) happens from the front.
A. Using Array (Static Queue)
   +-----+-----+-----+-----+-----+
   | 10  | 20  | 30  |     |     |
   +-----+-----+-----+-----+-----+
     ↑           ↑
   front        rear
The queue grows in one direction.

Fixed size (no dynamic resizing).

B. Using Linked List (Dynamic Queue)
Front → [10] → [20] → [30] → NULL
                            ↑
                           Rear
Memory is allocated dynamically.

No size limit (until memory is full).
*/

#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int items[SIZE];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    // Enqueue function
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full (Overflow)!" << endl;
        } else {
            rear++;
            items[rear] = value;
            cout << "Inserted: " << value << endl;
        }
    }

    // Dequeue function
    void dequeue() {
        if (front > rear) {
            cout << "Queue is empty (Underflow)!" << endl;
        } else {
            cout << "Deleted: " << items[front] << endl;
            front++;
        }
    }

    // Display queue
    void display() {
        if (front > rear) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Underflow case

    return 0;
}
/*Inserted: 10
Inserted: 20
Inserted: 30
Queue elements: 10 20 30
Deleted: 10
Queue elements: 20 30
Deleted: 20
Deleted: 30
Queue is empty (Underflow)! */

