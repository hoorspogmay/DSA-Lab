 #include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insert(int n) {
    Node *newnode = new Node;
    newnode->data = n;
    newnode->next = head;
    head=newnode;
}
void deleteFirst() {
    if (head == NULL) { 
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }
    Node *temp = head; 
    head = head->next;  
    delete temp; 
}


void display() {
    cout << "Data elements in a single linked list are: ";
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
	insert(5);
	insert(2);
	insert(4);
	insert(56);
	insert(21);
	
	display();
	
	deleteFirst();  

    cout << "After deleting the first node:" << endl;
    display();  
}