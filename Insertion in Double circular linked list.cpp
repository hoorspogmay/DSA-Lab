#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

Node* head = nullptr;

void display() {
	Node* temp = head;
	if(temp==nullptr) {
		cout<<"List is empty!!"<<endl;
		return;
	}
   do 
   {
	cout<<temp->data << " ";
	temp=temp->next;
	} while (temp != head); 
	cout << endl;

}
void insertStart(int val) {
	Node* newNode=new Node();
	newNode->data=val;	
	if (head==nullptr) 
	{
		head=newNode;
		newNode->prev=newNode;
	    newNode->next=newNode;
	}
	else
	{
	Node* last=head->prev;
	
	newNode->next=head;
	newNode->prev=last;
	last->next=newNode;
	head->prev=newNode;
	head=newNode;
   }

}

void insertMid(int val,int pos) {
	if (head==nullptr) {
		cout<<"List is empty, cannot insert in the middle." << endl;
		return;
	}
	Node* newNode=new Node();
	newNode->data=val;
	Node* temp=head;
	int count = 1;
	while (count<pos-1 && temp->next !=head) {
		temp = temp->next;
		count++;
	}
	if (count!=pos-1 && temp->next==head) {
		cout << "Position out of bounds." << endl;
		return;
	}
	newNode->next=temp->next;
	temp->next->prev=newNode;
	temp->next=newNode;
	newNode->prev=temp;
}

void insertEnd(int val) {

	Node* newNode = new Node();
	Node* last = head->prev;
	if(head==nullptr) {
		head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else
	{
	newNode->next=head;	
	newNode->data=val;
	newNode->prev=last;
	last->next=newNode;
	head->prev=newNode;
	}

}

int main() {
	while(true) {
		cout<<"****************"<<endl;
		cout<<"Insertion Double Circular Linked List"<<endl;
		cout<<"****************"<<endl;
		cout<<"Choose one option: "<<endl;
		cout<<"1)Insert At Start"<<endl;
		cout<<"2)Insert At Middle"<<endl;
		cout<<"3)Insert At End"<<endl;
		cout<<"4)Display"<<endl;
		cout<<"0)Exit"<<endl<<endl;

		int choice;
		cin>>choice;
		int val;
		switch(choice) {
			case 1:
				cout<<"Enter value you want to insert: "<<endl;
				cin>>val;
				insertStart(val);
				break;
			case 2:
				int pos;
				cout<<"Enter value you want to insert: "<<endl;
				cin>>val;
				cout<<"Enter position where you want to enter value: ";
				cin>>pos;
				insertMid(val,pos);
				break;
			case 3:
				cout<<"Enter value you want to insert: "<<endl;
				cin>>val;
				insertEnd(val);
				break;
			case 4:
				cout<<"List:"<<endl;
				display();
				break;
			case 0:
				exit(0);
			default:
				cout<<"Wrong choice entered!"<<endl;
		}

	}


	return 0;
}
