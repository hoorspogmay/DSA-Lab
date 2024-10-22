#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteStart() {
    if (head == nullptr) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
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
    for (int i = 0; i < pos - 1; i++) {
        if (temp->next == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    if (toDelete == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    temp->next = toDelete->next;
    delete toDelete;
}

void deleteEnd() {
    if (head == nullptr) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << "Data: " << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    while (true) {
        cout << "****************" << endl;
        cout << "Singly Linked List Menu" << endl;
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

