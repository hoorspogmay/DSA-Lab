 #include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertAtEnd(int n) {
    Node *newnode = new Node;
    newnode->data = n;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return ;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void deleteEnd() {
    if (head == NULL) { 
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }
    if(head->next==NULL)
    {
    	delete head;
    	head=NULL;
    	return;
	}
	
	 Node *temp = head;
    while (temp->next->next != NULL) {  // Find the second last node
        temp = temp->next;
    }
    delete temp->next;  // Delete the last node
    temp->next = NULL;  // Set the second last node's next to NULL
}

// Function to display the linked list
void display() {
    cout << "Data elements in a single linked list are: ";
    Node *temp = head;  // Start from the head node
    while (temp != NULL) {  // Traverse until the end of the list
        cout << temp->data << " ";  // Print data of current node
        temp = temp->next;  // Move to the next node
    }
    cout << endl;
}

int main() {
    // Inserting elements into the linked list
    insertAtEnd(5);
     insertAtEnd(2);
 insertAtEnd(4);
     insertAtEnd(56);
     insertAtEnd(21);

    cout << "Before deleting the last node:" << endl;
    display();  // Display the list before deletion

    deleteEnd();  // Delete the last node

    cout << "After deleting the last node:" << endl;
    display();  // Display the list after deletion
    
    return 0;
}