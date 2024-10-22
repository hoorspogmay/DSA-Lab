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
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteStart() {
    if (head == nullptr) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }
    
    Node* temp = head;
    if (head->next == nullptr) {
        head = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
}

void deleteMid(int pos) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; 
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void deleteEnd() {
    if (head == nullptr) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr; 
    }
    
    delete temp;
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
        cout << "Doubly Linked List Menu" << endl;
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
