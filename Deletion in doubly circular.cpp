#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
}

void deleteStart() {
    if (head == nullptr) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* last = head->prev;
        Node* temp = head;
        last->next = head->next;
        head->next->prev = last;
        head = head->next;
        delete temp;
    }
}

void deleteMid(int pos) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos == 0) {
        deleteStart();
        return;
    }

    Node* temp = head;
    int count = 0;

    while (count < pos) {
        temp = temp->next;
        count++;
        if (temp == head) {
            cout << "Position out of bounds!" << endl;
            return;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void deleteEnd() {
    if (head == nullptr) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;
    delete last;
}

void display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << "Data: " << temp->data << endl;
        temp = temp->next;
    } while (temp != head);
}

int main() {
    while (true) {
        cout << "****************" << endl;
        cout << "Doubly Circular Linked List Menu" << endl;
        cout << "****************" << endl;
        cout << "1) Insert Node" << endl;
        cout << "2) Delete Node from Start" << endl;
        cout << "3) Delete Node from Middle" << endl;
        cout << "4) Delete Node from End" << endl;
        cout << "5) Display List" << endl;
        cout << "0) Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        int val, pos;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                insert(val);
                break;
            case 2:
                deleteStart();
                break;
            case 3:
                cout << "Enter position to delete from (starting from 0): ";
                cin >> pos;
                deleteMid(pos);
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                display();
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
