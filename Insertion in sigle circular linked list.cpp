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
	while(temp->next!=head)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data<<" "<<endl; //printing data for the last node
	
}
int getsize()
{
	Node*temp = head;
	int count =1;
	if (head==nullptr)
	{
		return 0;
	}
	while(temp->next!=head)
	{
		temp=temp->next;
		count++;
	}
	return count;
}
void insertStart(int val)
{
	Node* newNode = new Node();
	    if (head == NULL) 
		{
            head = newNode;
            newNode->data=val;
            newNode->next = head;
        } 
		else 
		{
            Node* temp = head;
            while (temp->next != head) 
			{    
			temp = temp->next;
			}
			newNode->data=val;
            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
}
void insertEnd(int val)
{
	
	Node* newNode = new Node();
	Node* temp = head;
	if(temp==nullptr)
	{
		cout<<"List is empty!!";
		return;
	}
	while(temp->next!=head)
	{
		temp= temp->next;
	}
	newNode->data=val;
	temp->next=newNode;
	newNode->next=head;
}
void insertMid(int val,int pos)
{
	int count=1;
	Node* newNode = new Node();
	Node* temp = head;
	int size=getsize(); 
    if (pos<1 || pos>size+1)
    {
        cout<<"Position entered is out of bounds!" << endl;
        return;
    }
    if (pos == 1)
    {
        insertStart(val);
        return;
    }
    else if (pos==size+1)
    {
        insertEnd(val);
        return;
    }
	while(count!=(pos-1))
	{
		temp= temp->next;
		count++;
	}
	newNode->data=val;
    newNode->next=temp->next;
    temp->next=newNode;
}


int main()
{
	while(true)
	{
		cout<<"****************"<<endl;
		cout<<"Insertion Single Circular Linked List"<<endl;
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
		switch(choice)
		{
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
