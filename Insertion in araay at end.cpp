//insertion in array at middle
#include<iostream>
using namespace std;
int main()
{
	   int arr[6]={1,2,3,4,5};
	   int element;
	   int n=5;
	   int index;
	   
	   cout<<"Before Insertion:"<<endl;
	   for (int i=0;i<n;i++)
	   {
	   	cout<<arr[i]<<" ";
	   }  
	   
	   cout<<"\nEnter element you want to insert: "<<endl;
	   cin>>element; 
	   cout<<"Enter index where you want to enter: ";
	   cin>>index;
	   	
		for (int i=n;i>index;i--)
	   {
	   	arr[i]=arr[i-1];
	   } 

	      
       arr[index]=element;
       n++;
       
       cout<<"Array after insertion at beginning: ";
       for (int i=0;i<n;i++)
	   {
	   	cout<<arr[i]<<" ";
	   }

   return 0;
}
