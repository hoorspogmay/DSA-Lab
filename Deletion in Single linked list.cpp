#include<iostream>
using namespace std;

struct Node
{
   int data;
   Node* next;	
};

Node* head = nullptr;

void display()
{
	Node* temp = head;
	if(temp==nullptr)
	{
		cout<<"List is empty!!"<<endl;
		return;
	}
	while(temp!=nullptr)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
	
}
void insertStart(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}
void deleteStart()
{
	if(head==nullptr)
	{
		cout<<"List is empty!!"<<endl;
		return;
	}
	
	Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteMid(int pos)
{
	int count=1;
	Node* temp = head;
	if(temp==nullptr)
	{
		cout<<"List is empty!!";
		return;
	}
	if(pos==1)
	{
	deleteStart();	
		return;
	}
	while(count!=(pos-1))
	{
		temp= temp->next;
		count++;
	}
	if (temp->next == nullptr || temp->next->next == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }
	Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void deleteEnd()
{
	

	Node* temp = head;
	if(temp==nullptr)
	{
		cout<<"List is empty!!";
		return;
	}
	while(temp->next!=nullptr)
	{
		temp= temp->next;
	}
	delete temp->next;
	temp->next=nullptr;
	
}

int main()
{
	insertStart(32);
	insertStart(33);
	insertStart(34);
	insertStart(35);
	insertStart(36);
	insertStart(37);
	insertStart(38);
	insertStart(39);
	
	cout<<"Display initial list: "<<endl;
	display();
	
	while(true)
	{
		cout<<"****************"<<endl;
		cout<<"Deletion Single Linked List"<<endl;
		cout<<"****************"<<endl;
		cout<<"Choose one option: "<<endl;
		cout<<"1)Delete At Start"<<endl;
		cout<<"2)Delete At Middle"<<endl;
		cout<<"3)Delete At End"<<endl;
		cout<<"4)Display"<<endl;
		cout<<"0)Exit"<<endl<<endl;
		
		int choice;
		cin>>choice;
		int val;
		switch(choice)
		{
			case 1:
				
				deleteStart();
				break;
			case 2:
				int pos;
				cout<<"Enter position where you want to cdelete value: ";
				cin>>pos;
				deleteMid(pos);
				break;
			case 3:
				deleteEnd();
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

